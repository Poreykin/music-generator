music-generator
===============

Цели

1) Генерация музыкальной композции (произвольного жанра). (Глобально.)

Композиция - что-то что не режет слух. 

1.а) Генерация адекватной последовательности нот.

1.б) Генерация аккомпанемента для этой последовательности (с учетом правил).

2. (дальнейшее) Уметь воспроизводить сгенерированную мелодию.

3. (дальнейшее) Уметь генерировать и воспроизводить непрерывный поток.

Компоненты

Ноты - (громкость, частота, длительность)

Аккорды - (??? созвучие нот ???)

Шаблон(Послед-ть нот) - (набор изменений между соседними нотами в порядке звучания)

Аккомпанемент(Послед-ть аккордов) - (набор аккордов для придания благозвучности последовательности нот)

Звук - (массив, последовательность амплитуд) - задается с фиксированной глобально частотой дискретизации.

Проигрыватель - (переводит Звук в файл формата .wav);

(дальнейшее)	(воспроизводит Звук непосредственно);

Генератор

	Генератор мотива - (создание цепочки из шаблонов и стартовых нот)

	Генератор аккомпанемента - (создание акк. для мотива)

	(дальнейшее) Гармонизатор - (гармонизация полученной цепочки)

	Транслятор - (перевод полученной цепочки в Звук)

===============


