# VS Code Multiple Configurations Demo

This repo contains two simple C projects that share code all within the same repository. Each
project has its own Makefile. The main purpose is to provide an example of how to setup VS Code
Intellisense with multiple workspaces so that VS Code is aware of the includes and defines of each
project and sees the shared code but does not see code from other projects.

There are two solutions provided to this problem.

Project A:

- By utilizing multiple-root workspaces feature of VS Code we create an `a_project.code-workspace`
  file that also contains the intellisense configuration for the project. This has a downside that
  excluding files in VS Code can only be done to all roots simultaneously (see workspace file).

Project B:

- By placing a symlink to common within b_project we can treat `b_project` as a workspace root and
  VS Code is able to access all necessary code and we can configure intellisense for project B in
  the `b_project/.vscode` directory. This has the downside of not working by default on Windows, but
  using `git clone -c core.symlinks=true ...` should allow it to function but there may also be
  negative side-effects because there are multiple paths to the same file (directly and via
  symlink).

The Makefile included in each project also employes an interesting strategy to find C files in
specified directories and re-map them to a build output directory.
