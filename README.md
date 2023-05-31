# Zephyr Manifest Workspace Application

This is an example Zephyr "Hello World" application in its own West workspace.

It follows the concept described in [Improving Zephyr Project Structure with Manifest Files](https://blog.golioth.io/improving-zephyr-project-structure-with-manifest-files/). You are encouraged to read it to better understand what is going on in this project.

## Project Structure

`workspace/` is the workspace directory, the name is the name of the directory you cloned the repository to.

`workspace/.vscode` is the directory for Visual Studio Code configuration files. `c_cpp_properties.json` resolves include path errors in Visual Studio Code. Correct paths that are different on your machine.

`workspace/.west/config` is a plain text file that describes to west where the manifest file and where Zephyr is placed.

`workspace/application` is the directory for application specific files (`CMakeLists.txt`, `prj.conf`, `west.yml`, and more).

`workspace/application/boards` is the directory for custom boards.

`workspace/application/src` is the directory for application source code. Write your code here.

`workspace/build` is the directory for build output.

`workspace/deps` is the directory for dependencies. Zephyr goes here.

## Considerations

There are drawbacks to consider when using this project structure:

- The initial clone and west update of the project can take a long time.
- This project uses more disk space than an application living within the Zephyr SDK because each project carries around the Zephyr dependencies themselves.
- All projects need to be updated manually. This is not a drawback entirely, because it offers flexibility in versioning projects.

## Getting Started

Before getting started, make sure you have a proper Zephyr development environment installed. Follow the official [Zephyr Getting Started Guide](https://docs.zephyrproject.org/latest/develop/getting_started/index.html).

Clone the repository to a folder of your liking:

```shell
clone <url> workspace-name
```

Enter the workspace and update Zephyr modules:

```shell
cd workspace-name
west update
```

## Building and Running

Open Command Prompt inside the workspace directory.

Activate the West virtual environment. Change the path if yours is different:

```shell
# Windows (default installation)
%USERPROFILE%\zephyrproject\.venv\Scripts\activate.bat
```

Build for your board, here I build a pristine build for the `nRF52840 Development Kit`. Any supported board can be used instead:

```shell
west build -p always -b nrf52840dk_nrf52840 application
```

Once you have built the application, flash it to the board:

```shell
west flash
```
