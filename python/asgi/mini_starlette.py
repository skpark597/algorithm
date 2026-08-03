# ============================================================
# Response
# ============================================================


import json
from typing import Callable


class Response:
    def __init__(self, content: str, status_code: int = 200):
        self.content = content.encode()
        self.status_code = status_code

    async def __call__(self, scope, receive, send):
        await send(
            {
                "type": "http.response.start",
                "status": self.status_code,
                "headers": [(b"content-type", b"text/plain")],
            }
        )

        await send({"type": "http.response.body", "body": self.content})


class JSONResponse(Response):
    def __init__(self, content, status_code: int = 200):
        self.content = json.dumps(content).encode()
        self.status_code = status_code

    async def __call__(self, scope, receive, send):
        await send(
            {
                "type": "http.response.start",
                "status": self.status_code,
                "headers": [(b"content-type", b"application/json")],
            }
        )

        await send({"type": "http.response.body", "body": self.content})


# ============================================================
# Request
# ============================================================


class Request:
    def __init__(self, scope, receive):
        self.scope = scope
        self._receive = receive

    @property
    def method(self):
        return self.scope["method"]

    @property
    def path(self):
        return self.scope["path"]

    @property
    def headers(self):
        return dict(self.scope["headers"])


# ============================================================
# Route
# ============================================================


class Route:
    def __init__(self, path: str, endpoint: Callable, methods: list[str]):
        self.path = path
        self.endpoint = endpoint
        self.methods = methods

    def matches(self, scope):
        if scope["path"] != self.path:
            return False

        if scope["method"] not in self.methods:
            return False

        return True


# ============================================================
# Router
# ============================================================


class Router:
    def __init__(self, routes=None):
        self.routes: list[Route] = routes or []

    async def __call__(self, scope, receive, send):
        for route in self.routes:
            if route.matches(scope):
                request = Request(scope, receive)
                result = await route.endpoint(request)

                if isinstance(result, Response):
                    response = result

                elif isinstance(result, (dict, list)):
                    response = JSONResponse(result)

                else:
                    response = Response(str(result))

                await response(scope, receive, send)
                return

        response = Response("Not Found", status_code=404)
        await response(scope, receive, send)


# ============================================================
# Middleware
# ============================================================


class LoggingMiddleware:
    def __init__(self, app):
        self.app = app

    async def __call__(self, scope, receive, send):
        print(f"[Request] {scope['method']} {scope['path']}")
        await self.app(scope, receive, send)

        print("[Response] completed")


# ============================================================
# Starlette
# ============================================================


class Starlette:
    def __init__(self, routes=None, middleware=None):
        self.router = Router(routes)
        self.app = self.router

        if middleware:
            for middleware_class in reversed(middleware):
                self.app = middleware_class(self.app)

    async def __call__(self, scope, receive, send):
        await self.app(scope, receive, send)
