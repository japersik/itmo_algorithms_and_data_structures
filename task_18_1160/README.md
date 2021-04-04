#  Задача 18 (1067. Network)

## Условие

Andrew is working as system administrator and is planning to establish a new network in his company. There will be N hubs in the company, they can be connected to each other using cables. Since each worker of the company must have access to the whole network, each hub must be accessible by cables from any other hub (with possibly some intermediate hubs).
Since cables of different types are available and shorter ones are cheaper, it is necessary to make such a plan of hub connection, that the maximum length of a single cable is minimal. There is another problem - not each hub can be connected to any other one because of compatibility problems and building geometry limitations. Of course, Andrew will provide you all necessary information about possible hub connections.
You are to help Andrew to find the way to connect hubs so that all above conditions are satisfied.

    Ограничение времени: 1.0 секунды
    Ограничение памяти: 64 МБ


## Исходные данные

The first line contains two integer: N - the number of hubs in the network (2 ≤ N ≤ 1000) and M — the number of possible hub connections (1 ≤ M ≤ 15000). All hubs are numbered from 1 to N. The following M lines contain information about possible connections - the numbers of two hubs, which can be connected and the cable length required to connect them. Length is a positive integer number that does not exceed 106. There will be no more than one way to connect two hubs. A hub cannot be connected to itself. There will always be at least one way to connect all hubs.

## Результат
Output first the maximum length of a single cable in your hub connection plan (the value you should minimize). Then output your plan: first output P - the number of cables used, then output P pairs of integer numbers - numbers of hubs connected by the corresponding cable. Separate numbers by spaces and/or line breaks.

## Примеры
| Исходные данные | Результат  |
|---|---|
|4 <br>6 <br>1 2 1<br>1 3 1 <br>1 4 2<br>2 3 1<br>3 4 1<br>2 4 1<br>|1<br>4<br>1 2<br>1 3<br>2 3<br>3 4 |
