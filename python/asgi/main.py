from asgi.mini_starlette import LoggingMiddleware
from asgi.mini_fastapi import FastAPI
from asgi.mini_uvicorn import run


app = FastAPI(middleware=[LoggingMiddleware])


@app.get("/")
async def home(request):
    return {"message": "hello minifastapi"}


@app.get("/users")
async def users(request):
    return [{"id": 1, "name": "Liam"}, {"id": 2, "name": "Liam2"}]


@app.post("/users")
async def create_user(request):
    return {"message": "user created"}


if __name__ == "__main__":
    run(app)
