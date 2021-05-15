# Человекоподобный клиент-сервисный робот / Humanoid service robot
<img src="/imgs/c1/c1_2_full-hd.png" width="700"/>

*01.07.2020 - 31.07.2021*  [![Generic badge](https://img.shields.io/badge/Status-Active-green.svg)](https://shields.io/)<br/>

*Команда/Team*
1. [Андрей Недов](https://github.com/Andrey-Nedov-is-a-human)
- Лидер проекта
- Создание архитектуры, изготовление и установка аппаратного обеспечения
- Моделирование, изготовление и сборка конструкции и обшивки
- Написание софта на всех уровнях
- Подбор команды
- Поиск и получение предпосевных инвестиций на создание MVP
- Менеджмент
- Экспертиза

2. [Алина Горбунова](https://www.instagram.com/xhirchx/)
- Разработка, моделирование и рендеринг дизайн-концепта
- Моделирование обшивки

3. [Алексей Абахтимов](https://github.com/AmazingRoovy)
- Разработка систем распознавания объектов и лиц
<br/>

Проект является [моей](https://github.com/Andrey-Nedov-is-a-human) дипломной работой по окончании 4-го курса ИТ-факультета [Московского Политехнического Университета](https://new.mospolytech.ru/en/).

Научный руководитель [Идиатуллов Тимур Тофикович](https://old.mospolytech.ru/index.php?id=6714).

# Введение

<img src="/imgs/c1/4_full-hd.png" width="700"/>

# Передвижная платформа

<img src="/imgs/photos/2_3_1500.jpg" width="600"/>

## Конфигурация платформы

Для передвижения робот использует подвижную платформу, которая реализует схему трипода на омни-колесах. Такой подход, обеспечивая голономность системы, позволяет платформе, не совершая разворотов вокруг вертикальной оси, перемещаться в плоскости по любой заданной траектории.

<img src="/imgs/docs/result_vect.png" width="600"/>

Результирующий вектор направления робота альфа рассчитывается путём суммирования трёх векторов перемещения колёс платформы. Тогда управляющий сигнал для двигателей, нормированный в диапазоне от 0 до 255, будет рассчитываться как функция синуса от разницы полярного угла результирующего вектора и угла установки омни-колеса.

## Моделирование конструкиции платформы

Моделирование конструкции производилось в Autodesk Inventor.

<img src="/imgs/renders/platform/pl1_anim.gif" width="600"/>

## Состав компонентов





*Репозиторий в работе...*

