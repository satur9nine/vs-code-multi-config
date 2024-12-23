# VS Code Multiple Configurations Demo

This repo contains two simple C projects that share code. Each project has its own Makefile. The
main purpose is to provide an example of how to setup VS Code Intellisense with multiple
configurations so that VS Code is fully aware of the includes and defines of each project and sees
the shared code but does not see code from other projects.

Several attempts to get this working were made:

1. A single `c_cpp_properties.json` with multiple configurations: this failed because there is no
   way to exclude files per configuration so Intellisense processes all C source files for all
   configurations.
1. Multiple workspaces with each workspace utilizing the multi-root feature to include the project
   files and the common files: this failed because there isn't a way to place one
   `c_cpp_properties.json` for each workspace that applies to all roots. In this project the result
   was that when editing common.c and common.h VS Code just used a default Intellisense
   configuration. Creating a configuration at `common/.vscode/c_cpp_properties.json` caused VS Code
   to use when editing files in `common` but that configuration won't be project specific so this
   ultimately doesn't work.
1. Multiple workspaces and symlinks in each workspace root to common code: this setup succeeds in
   meeting the goals!
