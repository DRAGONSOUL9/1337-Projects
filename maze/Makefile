SRC = a_maze_ing.py

PKGS = requirments.txt
CONF = config.txt


install: $(PKGS)
	python3 -m venv venv
	source venv/bin/activate
	pip install -r $(PKGS)

run: $(SRC)
	python3 $(SRC) $(CONF)

clean:
	rm -rf __pycache__
	rm -rf .mypy_cache

lint:
	flake8 .
	mypy . --warn-return-any --warn-unused-ignores\
	--ignore-missing-imports --disallow-untyped-defs --check-untyped-defs

lint-strict:
	flake8 .
	mypy . --strict