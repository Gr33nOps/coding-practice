# Summer C++ Projects

A collection of **36 C++ projects** built during summer practice — console utilities, SFML games, and networked apps. Everything builds on **Visual Studio 18 (2026)** with the **v145** toolset, Win32 platform.

```
summer-cpp/
├── Console/    → 26 terminal apps (sorting, timers, passwords, string tricks)
├── Games/      →  8 games (SFML: flappy bird, snake, tic-tac-toe & more)
├── Network/    →  3 apps (Boost.Asio chat + networked tic-tac-toe)
└── README.md
```

---

## Requirements

| Dependency | Version | Where to get it |
|---|---|---|
| Visual Studio 18 | 2026 | Visual Studio Installer — *Desktop development with C++* |
| Toolset | v145 | Included with VS 18 |
| SFML | 2.6.1 | [sfml-dev.org](https://www.sfml-dev.org/download.php) |
| Boost | 1.86.0 | [boost.org](https://www.boost.org/) |

> **Note:** SFML (`SFML-2.6.1`) and Boost (`boost_1_86_0`) are **not** committed to this repo (large). Download them, place each copy in its project folder for SFML projects, and put Boost at the repo root for the network projects. Each SFML project expects a `SFML-2.6.1` folder next to its `.vcxproj`.

## How to build

Open any `.sln` in Visual Studio and press **F7** (Build), or from the command line:

```powershell
# Replace <path> with the project's .sln or .vcxproj
MSBuild.exe "<path>" /p:Configuration=Release /p:Platform=Win32 /m
```

The exe lands in the project's `Release\` folder.

---

## Console — `Console/`

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

## Games — `Games/`

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

## Network — `Network/`

| Project | Folder | Tech | What it is |
|---|---|---|---|
| Chat Server | `Chat Server/30.vcxproj` | Boost.Asio | TCP chat server (port 9999) |
| Chat Client | `Chat Client/31(2).vcxproj` | Boost.Asio | TCP chat client |
| Network Tic Tac Toe | `Network Tic Tac Toe/22.vcxproj` | Boost.Asio | 2-player tic-tac-toe over TCP (port 12345) |

---

## Notes

- **Ports:** Chat uses `9999`, Network Tic-Tac-Toe uses `12345` — run the server first, then connect from `127.0.0.1`.
- **Git hygiene:** build output (`Release/`, `Debug/`, `x64/`), SFML/Boost folders, `.dll`/`.exe`/`.obj` files are ignored via `.gitignore`.
- Built & tested with `MSBuild.exe` on VS 18 Community, toolset `v145`.
