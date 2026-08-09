# Coding Practice

A collection of practice projects across **C++**, **C#**, **Python**, and **Assembly** — built during coursework and summer practice. Everything is organized by language, then by category.

```
coding-practice/
├── C++/        → 37 projects (console utilities, SFML games, Boost networking)
│   ├── Console/    → 26 terminal apps
│   ├── Games/      →  8 SFML games
│   ├── Network/    →  3 Boost.Asio apps
│   ├── Operating system/ → OS scheduling algorithms
│   └── hello_world.cpp
├── C#/         → 25 projects (console, WinForms, MAUI, Xamarin)
│   ├── Console/    →  5 console apps
│   ├── WinForms/   → 16 desktop forms apps
│   └── Mobile/     →  4 MAUI/Xamarin apps
├── Python/     →  5 scripts (basics, variables, loops)
├── Assembly/   → 22 x86 assembly programs
└── README.md
```

---

## Requirements

| Dependency | Version | Where to get it |
|---|---|---|
| Visual Studio 18 | 2026 | Visual Studio Installer — *Desktop development with C++* |
| Toolset | v145 | Included with VS 18 |
| .NET SDK | 8.0 / 9.0 | [dotnet.microsoft.com](https://dotnet.microsoft.com/download) |
| SFML | 2.6.1 | [sfml-dev.org](https://www.sfml-dev.org/download.php) |
| Boost | 1.86.0 | [boost.org](https://www.boost.org/) |

> **Note:** SFML (`SFML-2.6.1`) and Boost (`boost_1_86_0`) are **not** committed (large). Download them, place a `SFML-2.6.1` folder next to each SFML project's `.vcxproj`, and put Boost at the repo root for the network projects.

## How to build

**C++ (MSBuild):**
```powershell
MSBuild.exe "<path-to>.sln" /p:Configuration=Release /p:Platform=Win32 /m
```

**C# (.NET):**
```powershell
dotnet build "<path-to>.sln"
```

Open any `.sln` in Visual Studio and press **F7** for either language.

---

## C++ Console — `C++/Console/`

| # | Project | Folder | What it does |
|---|---|---|---|
| 1 | Animated Hello World | `Animated Hello World/1.vcxproj` | Animated "Hello World" type effect |
| 2 | Alphabetical Sort | `Alphabetical Sort/2.vcxproj` | Sorting / min-deletions string logic |
| 3 | Even Odd Prime Checker | `Even Odd Prime Checker/3.vcxproj` | Even/odd/prime number checks |
| 4 | Number Guessing Game | `Number Guessing Game/4.vcxproj` | Guess-the-number game |
| 5 | Contact Manager | `Contact Manager/5.vcxproj` | Store and manage contacts |
| 6 | Output Manipulators Demo | `Output Manipulators Demo/6.vcxproj` | `std::setw`, `std::endl`, `std::flush` demos |
| 7 | StringStream Practice | `StringStream Practice/7.vcxproj` | `std::stringstream` practice |
| 8 | Word Frequency Counter | `Word Frequency Counter/8.vcxproj` | Count word occurrences in text |
| 9 | Reverse Word Order | `Reverse Word Order/9.vcxproj` | Reverse the order of words |
| 10 | String Functions Demo | `String Functions Demo/10.vcxproj` | Common string operations demo |
| 11 | Advanced String Operations | `Advanced String Operations/11.vcxproj` | More advanced string handling |
| 15 | Even Odd Counter | `Even Odd Counter/15.vcxproj` | Count even/odd numbers |
| 16 | Character Analyzer | `Character Analyzer/16.vcxproj` | Analyze input characters |
| 17 | Pakistan Flag | `Pakistan Flag/17.vcxproj` | Draw the flag with console art |
| 18 | Current Time Display | `Current Time Display/18.vcxproj` | Show current system time |
| 19 | Stopwatch | `Stopwatch/19.vcxproj` | Stopwatch timing challenge |
| 20 | Countdown Timer | `Countdown Timer/20.vcxproj` | Countdown timer |
| 21 | Clock Countdown Timer | `Clock Countdown Timer/21.vcxproj` | Clock-style countdown |
| 23 | Catch the Letter Game | `Catch the Letter Game/23.vcxproj` | Catch falling letters |
| 24 | Password Manager | `Password Manager/24.vcxproj` | Save & manage passwords |
| 25 | Arrow Key Password Setter | `Arrow Key Password Setter/25.vcxproj` | Set password with arrow keys |
| 26 | Number Lock Password | `Number Lock Password/26.vcxproj` | Number-lock password entry |
| 27 | Password Strength Checker | `Password Strength Checker/27.vcxproj` | Score password strength |
| 33 | Car Manager | `Car Manager/33.vcxproj` | Car records manager |
| — | ABDULRAHMAN PROJECT | `ABDULRAHMAN PROJECT/` | Personal project (Quran/surah themed) |
| — | Analog Clock | `analog clock/` | Analog clock console app |

## C++ Games — `C++/Games/`

| Project | Folder | Tech | What it is |
|---|---|---|---|
| flappyBird | `flappyBird/` | SFML 2.6.1 | Flappy bird clone |
| SnakeGame | `Snake game/` | SFML 2.6.1 | Snake game |
| tic tac t | `tic tac t/` | SFML 2.6.1 | Tic-tac-toe |
| SFML Tic Tac Toe | `SFML Tic Tac Toe/` | SFML 2.6.1 | Tic-tac-toe |
| game 1 | `game1/game 1/` | SFML (sibling `sfml`) | Arcade game |
| game 1 (try 2) | `game1/game 1 (try 2)/` | SFML (sibling `sfml`) | Arcade game rework |
| gameone | `gameone/` | SFML 2.6.1 | Game |
| game | `game semester 1project/game/` | — | Semester game |

## C++ Network — `C++/Network/`

| Project | Folder | Tech | What it is |
|---|---|---|---|
| Chat Server | `Chat Server/30.vcxproj` | Boost.Asio | TCP chat server (port 9999) |
| Chat Client | `Chat Client/31(2).vcxproj` | Boost.Asio | TCP chat client |
| Network Tic Tac Toe | `Network Tic Tac Toe/22.vcxproj` | Boost.Asio | 2-player tic-tac-toe over TCP (port 12345) |

## C++ OS — `C++/Operating system/`

| Project | Folder | What it is |
|---|---|---|
| FCFS Algorithm | `Operating system.cpp` | FCFS process scheduling |
| OS.c | `OS.c` | Fork/system-call demos |

## C# Console — `C#/Console/`

| Project | What it is |
|---|---|
| HelloWorld | Hello World template |
| ConditionalLogicDemo | If/switch conditional logic |
| LongestWordFinder | Longest word in a file |
| CSharpBasicsLab | C# basics with commented examples |
| ExamPractice | Namespaces, factorial, linear/bubble/selection sort |

## C# WinForms — `C#/WinForms/`

| Project | What it is |
|---|---|
| Basic Greeting Form | Greeting form |
| Calculator | Calculator |
| Database Operation | Database operations |
| Dodger Game | Dodger game |
| DodgerGame copy | Duplicate of Dodger Game |
| Form Final Boss | Form project |
| gender and country selector | Gender/country picker |
| GPA CALCULATOR | GPA calculator |
| HAPPY BIRTHDAY | Birthday form |
| Hello World Form | Hello World form |
| HelloWorld Console | Hello World console app |
| ListBox | ListBox demo |
| Login System | Login form |
| Salary Slip | Salary slip form |
| BlankForm | Empty WinForms template |
| PresentationForm | Empty form for presentation |

## C# Mobile — `C#/Mobile/`

| Project | What it is |
|---|---|
| MAUI/HappyBirthday CakeAnimation | MAUI app with cake animation |
| MAUI/HappyBirthdayApp | MAUI birthday app |
| HappyBirthday Xamarin | Older Xamarin.Forms app (Android + iOS) |

## Python — `Python/`

| File | What it does |
|---|---|
| 01-hello-world.py | Prints Hello World |
| 02-greet-user.py | Reads a name and greets the user |
| 03-variables-demo.py | Variables of different types |
| 04-even-odd-and-sign.py | Even/odd + sign check |
| 05-loops-demo.py | For and while loops |

## Assembly — `Assembly/`

| File | What it does |
|---|---|
| hello-world.asm / hello-world-2.asm | Print hello world |
| add-two-numbers.asm | Add two numbers |
| subtract-two-numbers.asm | Subtract two numbers |
| larger-of-two-numbers.asm | Find larger of two |
| smallest-of-three-numbers.asm | Find smallest of three |
| factorial.asm | Factorial |
| sum-of-array.asm | Sum an array |
| bubble-sort.asm / bubble-sort-local-variables.asm / bubble-sort-subroutine-stack.asm | Bubble sort variants |
| linear-search.asm / binary-search.asm | Search algorithms |
| 4-bit-manipulation.asm | Bit manipulation |
| add-two-numbers-stack-parameters.asm | Stack-parameter calls |
| add-using-subroutine.asm | Subroutine call |
| enter-and-display-character.asm | Character input/output |
| print-by-character.asm / print-by-loop.asm | Print loops |
| print-character-on-screen.asm / print-digit-on-screen.asm | Print char/digit |
| stack-example.asm | Stack usage |

---

## Notes

- **Ports:** Chat uses `9999`, Network Tic-Tac-Toe uses `12345` — run the server first, then connect from `127.0.0.1`.
- **Git hygiene:** build output (`Release/`, `Debug/`, `x64/`, `bin/`, `obj/`), SFML/Boost folders, `.dll`/`.exe`/`.apk`/`.obj` files are ignored via `.gitignore`.
- Built & tested with `MSBuild.exe` on VS 18 Community, toolset `v145`.
