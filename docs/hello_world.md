
# Docker 
- build image
`docker build . -t machikoro`

- 執行
`docker compose down && docker compose up -d`

- 進入container
`docker exec -it machi-koro-cpp-machikoro-1  bash`
注意container 名字：machi-koro-cpp-machikoro-1 是否有不一樣要換