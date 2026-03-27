FROM    ubuntu:24.04

RUN     apt-get update && apt-get install -y build-essential libreadline-dev

WORKDIR /app

COPY    . /app

RUN     cd libft && make && cd .. &&  make && make clean && \
        rm -rf inc && rm -rf libft && rm -rf src && rm Makefile

CMD     ["./minishell"]