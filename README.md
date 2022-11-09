## Code by [cuzperf](https://codeforces.com/profile/cuzperf)

Source Code In Codeforces.

## Use [cf-tool](https://github.com/xalanq/cf-tool)

My config:

``` shell
clang++ $%full%$ -o $%file%$.out -std=c++17 -Wall -Wshadow -ftrapv -Wno-error -g -fsanitize=undefined
```

> Note than `D_GLIBCXX_DEBUG` may hide debug info, and `-Wextra` may be too annoy

`.vscode/launch.json` 配置：

``` json
{
  // clang++ main.cpp -o main.out -std=c++17 -Wall -Wshadow -ftrapv -Wno-error -g -fsanitize=undefined
  // .vscode/launch.json need vscode extension: codelldb and replace 1722 with current contest id

  // Use IntelliSense to learn about possible attributes.
  // Hover to view descriptions of existing attributes.
  // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
  "version": "0.2.0",
  "configurations": [
    {
      "type": "lldb",
      "request": "launch",
      "name": "c",
      "program": "${workspaceFolder}/contest/1722/c/c.out",
      "args": [],
      "cwd": "${workspaceFolder}/contest/1722/c",
    },
    {
      "type": "lldb",
      "request": "launch",
      "name": "main",
      "program": "${workspaceFolder}/main.out",
      "args": [],
      "cwd": "${workspaceFolder}",
    },
  ]
}
```

## Genius

- [tourist](https://codeforces.com/profile/tourist): legend
- [jiangly](https://codeforces.com/profile/jiangly): clear ideal, nice code style
- [rainboy](https://codeforces.com/profile/rainboy): C
- [clyring](https://codeforces.com/submissions/clyring): Haskell
- [Haskell_for_a_pint](https://codeforces.com/profile/Haskell_for_a_pint): Haskell
