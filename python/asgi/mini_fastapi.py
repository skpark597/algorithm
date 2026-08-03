from asgi.mini_starlette import Starlette, Route


class FastAPI(Starlette):
    def get(self, path):
        def decorator(endpoint):
            self.router.routes.append(Route(path, endpoint, ["GET"]))
            return endpoint

        return decorator

    def post(self, path):
        def decorator(endpoint):
            self.router.routes.append(Route(path, endpoint, ["POST"]))
            return endpoint

        return decorator
