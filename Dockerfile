FROM ubuntu:24.04

RUN apt-get update
RUN apt-get install -y build-essential libreadline-dev

WORKDIR /app

COPY . /app

CMD ["bash"]