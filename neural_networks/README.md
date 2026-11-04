# Neural Networks

Notes and experiments on neural network fundamentals, using interactive marimo
notebooks.

## Notebooks

- [`building_micrograd/main.py`](building_micrograd/main.py): work in progress
  exploring a polynomial, plotting its values, and estimating its derivative with
  finite differences. Includes a micrograd reference example.

## Getting started

Requires Python 3.15 and `uv`. Run these commands from this directory:

```sh
uv sync
uv run marimo edit building_micrograd/main.py
```

The editor opens in your browser. Dependencies are defined in `pyproject.toml` and
locked in `uv.lock`.

To start the editor for remote access:

```sh
uv run marimo edit building_micrograd/main.py --host <host-ip> --port <port> --headless
```

Replace `<host-ip>` with the host's reachable IP address and `<port>` with your
chosen port. Open `http://<host-ip>:<port>` in your browser, using the access token
from the terminal URL if prompted.
