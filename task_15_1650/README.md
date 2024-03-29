#  Задача 15 (1650. Миллиардеры)

## Условие

Возможно, вы знаете, что из всех городов мира больше всего миллиардеров живёт в Москве. Но, поскольку работа миллиардера подразумевает частые перемещения по всему свету, в определённые дни какой-то другой город может занимать первую строчку в таком рейтинге. Ваши приятели из ФСБ, ФБР, MI5 и Шин Бет скинули вам списки перемещений всех миллиардеров за последнее время. Ваш работодатель просит посчитать, сколько дней в течение этого периода каждый из городов мира был первым по общей сумме денег миллиардеров, находящихся в нём.

    Ограничение времени: 3.0 секунды
    Ограничение памяти: 64 МБ


## Исходные данные

В первой строке записано число n — количество миллиардеров (1 ≤ n ≤ 10000). Каждая из следующих n строк содержит данные на определённого человека: его имя, название города, где он находился в первый день данного периода, и размер состояния. В следующей строке записаны два числа: m — количество дней, о которых есть данные (1 ≤ m ≤ 50000), k — количество зарегистрированных перемещений миллиардеров (0 ≤ k ≤ 50000). Следующие k строк содержат список перемещений в формате: номер дня (от 1 до m − 1), имя человека, название города назначения. Вы можете считать, что миллиардеры путешествуют не чаще одного раза в день, и что они отбывают поздно вечером и прибывают в город назначения рано утром следующего дня. Список упорядочен по возрастанию номера дня. Все имена и названия городов состоят не более чем из 20 латинских букв, регистр букв имеет значение. Состояния миллиардеров лежат в пределах от 1 до 100 миллиардов.

## Результат
В каждой строке должно содержаться название города и, через пробел, количество дней, в течение которых этот город лидировал по общему состоянию миллиардеров, находящихся в нём. Если таких дней не было, пропустите этот город. Города должны быть отсортированы по алфавиту (используйте обычный порядок символов: ABC...Zabc...z).

## Примеры
| Исходные данные | Результат  |
|---|---|
|5<br>Abramovich London 15000000000<br>Deripaska Moscow 10000000000<br>Potanin Moscow 5000000000<br>Berezovsky London 2500000000<br>Khodorkovsky Chita 1000000000<br>25 9<br>1 Abramovich Anadyr<br>5 Potanin Courchevel<br>10 Abramovich Moscow<br>11 Abramovich London<br>11 Deripaska StPetersburg<br> 15 Potanin Norilsk<br>20 Berezovsky Tbilisi<br>21 Potanin StPetersburg<br>22 Berezovsky London|Anadyr 5<br>London 14<br>Moscow 1|
