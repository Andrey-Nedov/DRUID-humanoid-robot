# Человекоподобный клиент-сервисный робот / Humanoid service robot
<img src="/imgs/c1/c1_2_full-hd.png" width="700"/>

*01.07.2020 - 31.07.2021*  [![Generic badge](https://img.shields.io/badge/Status-Active-green.svg)](https://shields.io/)<br/>

*Команда/Team*
1. [Андрей Недов](https://github.com/Andrey-Nedov-is-a-human)
- Лидер проекта
- Создание архитектуры, изготовление и установка аппаратного обеспечения
- Моделирование, изготовление и сборка конструкции и обшивки
- Написание софта на всех уровнях
- Разработка дизайн-концепта
- Подбор команды
- Поиск и получение предпосевных инвестиций на создание MVP
- Менеджмент
- Экспертиза
- Медиапроизводство

2. [Алина Горбунова](https://www.instagram.com/xhirchx/)
- Разработка, моделирование и рендеринг дизайн-концепта
- Моделирование обшивки

3. [Алексей Абахтимов](https://github.com/AmazingRoovy)
- Разработка систем распознавания объектов и лиц
<br/>

Проект является моей [(Andrey-Nedov-is-a-human)](https://github.com/Andrey-Nedov-is-a-human) дипломной работой по окончании 4-го курса ИТ-факультета [Московского Политехнического Университета](https://new.mospolytech.ru/en/). 

Научный руководитель [Идиатуллов Тимур Тофикович](https://old.mospolytech.ru/index.php?id=6714).

Финансирует проект компания [Диджитал Репаблик](https://di-re.ru/) с целью дальнейешго производства серии.

# О проекте

[inst @druid_robotics](https://www.instagram.com/druid_robotics/)

<img src="/imgs/c1/4_full-hd.png" width="700"/>

_Репозиторий в работе..._

# Передвижная платформа

<img src="/imgs/photos/2_3_1500.jpg" width="600"/>

## Конфигурация платформы

Для передвижения робот использует подвижную платформу, которая реализует схему трипода на омни-колесах. Такой подход, обеспечивая голономность системы, позволяет платформе, не совершая разворотов вокруг вертикальной оси, перемещаться в плоскости по любой заданной траектории.

<img src="/imgs/docs/result_vect.png" width="600"/>

Результирующий вектор направления рассчитывается путём суммирования трёх векторов перемещения колёс платформы. Тогда управляющий сигнал для двигателей, нормированный в диапазоне от 0 до 255, будет рассчитываться как функция синуса от разницы полярного угла результирующего вектора и угла установки омни-колеса.

## Моделирование конструкиции платформы

Моделирование конструкции производилось в Autodesk Inventor.

<img src="/imgs/renders/platform/pl1_anim.gif" width="600"/>

<p>
  <img src="/imgs/docs/frame.jpg" width="260"/>
  <img src="/imgs/docs/plate.png" width="240"/>
  <img src="/imgs/docs/motor.png" width="220"/>
  <img src="/imgs/docs/motor_f.png" width="120"/>
</p>

Основой конструкции платформы робота является рама из стального профиля толщиной 20 мм. 
Рама создавалась методами резки и сварки металла и смоделирована таким образом чтобы все компоненты платформы могли быть помещены внутрь неё. Частично вынесены наружу были только двигатели из-за их крупных габаритов.

К раме прикреплены стальные пластины толщиной 4 мм, вырезанные на плазменной установке с ЧПУ, которые являются опорой для двигателей. Сталь такой толщины позволяет платформе выдерживать большие нагрузки, избегая деформаций.

<img src="/imgs/photos/2_3_1501.JPG" width="600"/> 

### Система охлаждения

Работа драйвера электродвигателя сопровождается выделением тепла, поэтому радиаторы драйверов двигателей нуждаются в дополнительном отводе тепла. Было принято решение создать систему охлаждения радиаторов.

<img src="/imgs/renders/platform/pl2_anim.gif" width="600"/> 

Необходимые детали были изготовлены при помощи 3D-печати, собраны и установлены в платформу. Для изготовления воздуховодов использовался пластик PLA. Также в систему охлаждения был установлен датчик температуры, который собирает информацию о температуре выходящего потока воздуха.

<img src="/imgs/photos/cool_s.png" width="600"/> 


## Состав компонентов 

В качестве основных двигателей были выбраны 60-ти Ваттные двигатели постоянного тока с установленными на них червязными редукторами. Такая конструкция позволяет отвести корпус двигателей от внутренностей платформы освободив место для аккумулятора и других компонентов. С одной стороны червячные редукторы дают большое передаточное число, что сильно понижает сокрость и повышает момент на выходном валу. В нашем случае это очень кстати, ведь нашему роботу большие скорости ни к чему, а вот момент для того чтобы срываться с места очень нужен. С другой стороны червячные редукторы дают сильные потери энергии и не позволяют перетаскивать робота по поверхности.

В роли управляющих контроллеров была использована плата _Arduino Mega 2560_ в связке с драйвером двигателей постоянного тока на базе чипа _L298_. Последняя может выдерживать ток до 15 апмер, значит наши нагрузки ей будут нипочём.

Дополнительное требование к платформе – возможность её использования независимо от тела робота. Такой подход не только даёт нам возможность отладки платформы на ранних стадиях разработки всего робота, но и использования платформы в других проектах. Для этого в системе платформы предусмотрен дополнительный одноплатный компьютер _Raspberry PI_, который может выступать в качестве управляющего блока, замены верхнему уровню робота.

Питается система от 12-ти вольтового свинцово-кислотного аккумуятора ёмкостью 26 Ампер-часов. Хватает на 5-6 часов активности.

## ПО платформы

Управлять платформой можно как с персонального компьютера, так и со смартфона. Причём никакого стороннего ПО для этого ставить не надо. Стоит только подключиться к wi-fi
сети DRUID которую раздаёт сама платформа и в браузере перейти по специальному IP-адресу. Платформа сама загрузит вам пульт прямо в браузере.

<img src="/imgs/docs/pl_soft.png" width="700"/>

Система работает следующим образом. В платформе установлен wi-fi роутер, на котором развёрнута локальная сеть без доступа в интернет. Роутер перенапрявляет запросы по специальному IP на порт сервера развёрнутого на Raspberry, который прослушивается HTTP сервером. Далее на устройсво клиента скачивается пакет JS/HTML/CSS и медиа файлов которые составляют пульт управления платформой. Фронт часть пульта адаптируется под соотношеине сторон дисплея клиента и переключается между мобильной к десктопной версиями. Также пуль поддерживает мультитач.

<p>
  <img src="/imgs/photos/1.png" width="200"/>
  <img src="/imgs/photos/1_1.png" width="550"/>
</p>

Как результат:

<img src="/imgs/video/works_360.gif" width="300"/>

## Съёмки промо

Для публикации в медиа отсняли небольшой проморолик по промежуточнуму результату

[Youtube](https://www.youtube.com/watch?v=_gj3ynNgX4c)

<img src="/imgs/promo/promo3_480.gif" width="700"/>

*Репозиторий в работе... Далее расскажу про верхнюю часть робота и оболочку*

