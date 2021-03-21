#  Задача 11 (1067. Disk Tree)

## Условие

СHacker Bill has accidentally lost all the information from his workstation's hard drive and he has no backup copies of its contents. He does not regret for the loss of the files themselves, but for the very nice and convenient directory structure that he had created and cherished during years of work.
Fortunately, Bill has several copies of directory listings from his hard drive. Using those listings he was able to recover full paths (like `"WINNT\SYSTEM32\CERTSRV\CERTCO~1\X86"`) for some directories. He put all of them in a file by writing each path he has found on a separate line.
Your task is to write a program that will help Bill to restore his state of the art directory structure by providing nicely formatted directory tree.

    Ограничение времени: 1.0 секунды
    Ограничение памяти: 64 МБ


## Исходные данные

The first line of the input contains single integer number N (1 ≤ N ≤ 500) that denotes a total number of distinct directory paths. Then N lines with directory paths follow. Each directory path occupies a single line and does not contain any spaces, including leading or trailing ones. No path exceeds 80 characters. Each path is listed once and consists of a number of directory names separated by a back slash ("\").
Each directory name consists of 1 to 8 uppercase letters, numbers, or the special characters from the following list: exclamation mark, number sign, dollar sign, percent sign, ampersand, apostrophe, opening and closing parenthesis, hyphen sign, commercial at, circumflex accent, underscore, grave accent, opening and closing curly bracket, and tilde ("!#$%&'()-@^_`{}~").

## Результат
Write to the output the formatted directory tree. Each directory name shall be listed on its own line preceded by a number of spaces that indicate its depth in the directory hierarchy. The subdirectories shall be listed in lexicographic order immediately after their parent directories preceded by one more space than their parent directory. Top level directories shall have no spaces printed before their names and shall be listed in lexicographic order. See sample below for clarification of the output format.

## Примеры
| Исходные данные | Результат  |
|---|---|
|7<br>WINNT\SYSTEM32\CONFIG<br>GAMES<br>WINNT\DRIVERS<br>HOME<br>WIN\SOFT<br>GAMES\DRIVERS<br>WINNT\SYSTEM32\CERTSRV\CERTCO~1\X86<br>|GAMES<br>_DRIVERS<br>HOME<br>WIN<br>_SOFT<br>WINNT<br>_DRIVERS<br> _SYSTEM32<br>__CERTSRV<br>___CERTCO~1<br>____X86<br>__CONFIG |
