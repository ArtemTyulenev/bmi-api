FROM drogonframework/drogon AS build

WORKDIR /src

COPY . .

RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release 
&& cmake --build build --parallel "$(nproc)"

FROM drogonframework/drogon

RUN apt-get update 
&& apt-get install -y --no-install-recommends curl 
&& rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY --from=build /src/build/imt ./imt
COPY config.json ./config.json

EXPOSE 8081

HEALTHCHECK --interval=30s 
--timeout=3s 
--start-period=10s 
--retries=3 
CMD curl -fsS http://127.0.0.1:8081/api/bmi/75/175 || exit 1

CMD ["./imt"]