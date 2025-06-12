FROM python:3.11-slim
WORKDIR /app
COPY target_server.py .
RUN mkdir /logs
VOLUME /logs
CMD ["python", "target_server.py"]
