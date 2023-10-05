name = inception

all:
	@bash srcs/requirements/wordpress/tools/make_dir.sh
	@docker-compose -f ./srcs/docker-compose.yml --env-file srcs/.env up -d

build:
	@bash srcs/requirements/wordpress/tools/make_dir.sh
	@docker-compose -f ./srcs/docker-compose.yml --env-file srcs/.env up -d

down:
	@docker-compose -f ./srcs/docker-compose.yml --env-file srcs/.env down

re: down
	@docker-compose -f ./srcs/docker-compose.yml --env-file srcs/.env up -d

fclean:
	@docker stop $$(docker ps --all --quiet)
	@docker system prune --all --force --volumes
	@if [ -d /home/$(USER)/data ]; then \
		sudo rm -rf /home/$(USER)/data; \
	fi

