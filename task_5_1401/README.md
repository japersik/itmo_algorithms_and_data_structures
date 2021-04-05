#  Задача 5 (1401. Игроки)

## Условие

Известно, что господин Чичиков зарабатывал свой капитал и таким способом: он спорил со всякими недотёпами, что сможет доказать, что квадратную доску размера 512 × 512 нельзя замостить следующими фигурами:

    X       XX       X      XX
    XX      X       XX       X
и всегда выигрывал. Однако один из недотёп оказался не так уж глуп, и сказал, что сможет замостить такими фигурами доску размера 512 × 512 без правой верхней клетки. Чичиков, не подумав, ляпнул, что он вообще может любую доску размера 2<sup>n</sup> × 2<sup>n</sup> без одной произвольной клетки замостить такими фигурами. Слово за слово, они поспорили. Чичиков чувствует, что сам он не докажет свою правоту. Помогите же ему!

    Ограничение времени: 3.0 секунды
    Ограничение памяти: 64 МБ

## Исходные данные

В первой строке записано целое число n (1 ≤ n ≤ 9). Во второй строке через пробел даны два целых числа x, y: координаты «выколотой» клетки доски (1 ≤ x, y ≤ 2<sup>n</sup>), x — номер строки, y — номер столбца. Левый верхний угол доски имеет координаты (1, 1).
## Результат
Ваша программа должна выдать 2<sup>n</sup> строчек по 2<sup>n</sup> чисел в каждой строке. На месте выбитой клетки должно стоять число 0. На месте остальных клеток должны стоять числа от 1 до (2<sup>2n</sup> − 1) / 3 — номер фигуры, закрывающей данную клетку. Разумеется, одинаковые номера должны образовывать фигуры. Если же такую доску нельзя покрыть фигурами, выведите «−1».

## Примеры
| Исходные данные | Результат  |
|---|---|
| 2 <br> 1 1 <br> | 0 1 3 3<br> 1 1 4 3<br> 2 4 4 5<br> 2 2 5 5 |