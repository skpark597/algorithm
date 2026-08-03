import asyncio


class MiniUvicorn:
    def __init__(self, app, host="127.0.0.1", port=8000):
        self.app = app
        self.host = host
        self.port = port

    async def handle_connection(self, reader: asyncio.StreamReader, writer: asyncio.StreamWriter):
        data = await reader.read(65536)

        print("Raw HTTP Request:")
        print(data.decode())

        request_line = data.split(b"\r\n", 1)[0]
        method, path, version = request_line.split()

        scope = {
            "type": "http",
            "asgi": {"version": "3.0"},
            "http_version": "1.1",
            "method": method.decode(),
            "scheme": "http",
            "path": path.decode(),
            "raw_path": path,
            "query_string": b"",
            "headers": [],
        }

        async def receive():
            return {"type": "http.request", "body": b"", "more_body": False}

        async def send(message):
            if message["type"] == "http.response.start":
                status = message["status"]
                status_text = {200: "OK", 404: "Not Found"}.get(status, "Unknown")

                writer.write(f"HTTP/1.1 {status} {status_text}\r\n".encode())

                for name, value in message["headers"]:
                    writer.write(name + b": " + value + b"\r\n")

                writer.write(b"\r\n")

            elif message["type"] == "http.response.body":
                body = message["body"]
                writer.write(body)

                await writer.drain()
                writer.close()

        await self.app(scope, receive, send)

    async def run(self):
        server = await asyncio.start_server(self.handle_connection, self.host, self.port)

        print(f"MiniUviconrn running on http://{self.host}:{self.port}")

        async with server:
            await server.serve_forever()


def run(app, host="127.0.0.1", port=8000):
    server = MiniUvicorn(app, host, port)
    asyncio.run(server.run())
