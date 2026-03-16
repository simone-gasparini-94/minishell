FROM    ubuntu:24.04

RUN     apt-get update
RUN     apt-get install -y build-essential libreadline-dev

WORKDIR /app

COPY    . /app

RUN     cd libft && make && cd ..
RUN     make
RUN     rm -rf assets && rm -rf inc && rm -rf libft && rm -rf src && rm Makefile \
        && rm -rf build

CMD     ["./minishell"]