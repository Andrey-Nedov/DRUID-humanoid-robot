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

Проект является моей [(Andrey-Nedov-is-a-human)](https://github.com/Andrey-Nedov-is-a-human) дипломной работой по окончании 4-го курса ИТ-факультета [Московского Политехнического Университета](https://new.mospolytech.ru/en/). Образовательная программа [киберфизические системы](https://old.mospolytech.ru/index.php?id=5318).

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
Рама создавалась методами резки и сварки металла и смоделирована таким образом, чтобы все компоненты платформы могли быть помещены внутрь неё. Частично вынесены наружу были только двигатели из-за их крупных габаритов. Пластиковые крышки вырезались на лазерном ЧПУ-станке.

К раме прикреплены стальные пластины толщиной 4 мм, вырезанные на плазменной установке с ЧПУ, которые являются опорой для двигателей. Сталь такой толщины позволяет платформе выдерживать большие нагрузки, избегая деформаций.

<img src="/imgs/photos/2_3_1501.JPG" width="600"/> 

### Система охлаждения

Работа драйвера электродвигателя сопровождается выделением тепла, поэтому радиаторы драйверов двигателей нуждаются в дополнительном отводе тепла. Было принято решение создать систему охлаждения радиаторов.

<img src="/imgs/renders/platform/pl2_anim.gif" width="600"/> 

Необходимые детали были изготовлены при помощи 3D-печати, собраны и установлены в платформу. Для изготовления воздуховодов использовался пластик PLA. Также в систему охлаждения был установлен датчик температуры, который собирает информацию о температуре выходящего потока воздуха.

<img src="/imgs/photos/cool_s.png" width="600"/> 


## Состав компонентов 

В качестве основных двигателей были выбраны 60-ти ваттные двигатели постоянного тока с установленными на них червячными редукторами. Такая конструкция позволяет отвести корпус двигателей от внутренностей платформы освободив место для аккумулятора и других компонентов. С одной стороны червячные редукторы дают большое передаточное число, что сильно понижает сокрость и повышает момент на выходном валу. В нашем случае это очень кстати, ведь нашему роботу большие скорости ни к чему, а вот момент для того чтобы срываться с места очень нужен. С другой стороны червячные редукторы дают сильные потери энергии и не позволяют перетаскивать робота по поверхности.

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

Для публикации в медиа съездили в DIY-магазни, закупили освещение, из дома взял камеру с линзами, отражатели и, в помещении финансирующей компании, отсняли небольшой проморолик по промежуточнуму результату.

[Youtube](https://www.youtube.com/watch?v=_gj3ynNgX4c)

<img src="/imgs/promo/promo3_480.gif" width="700"/>

Чтобы добиться от робота плавных движений использовал синусоидальные функции эксперементируя с фазами. Кстати, весь съёмочный день, это часов 5-6, робот катался без подзарядки.

<br/><br/><br/>

# Центральная опора

Центральная опора робота выполняет роль каркаса для всех компонентов системы аниматроники. Она выполнена из стального профиля толщиной 20мм методами резки и сварки металла, что обеспечивает прочность конструкции. 

<img src="/imgs/renders/support.jpg" width="760"/>

Для соединения отдельных частей опоры между собой, крепления опоры к платформе и установки оборудования используются болтовые соединения с самоконтрящимися гайками. По всей поверхности опоры были просверлены дополнительные отверстия для крепления компонентов системы аниматроники.

Для крепления опоры к платформе используется всего три болта, для крепления рук, используется по одному болту на каждую руку

<p>
  <img src="/imgs/photos/8.jpg" width="250"/>
  <img src="/imgs/photos/7.jpg" width="250"/>
</p>


<br/><br/><br/>

# Руки

<img src="/imgs/photos/2_6_1500.jpg" width="700"/>

Большое количество времени проекта ушло на разработку рук робота. Клиент-сервисному роботу руки нужны для жестикуляции во время общения с человеком. Вопрос насколько правдоподобно рука робота должна копировать подвижность человеческой на начало работы был открытым. В результате был пройден путь по упрощению конструкции до достижения баланса между простотой в изготовлении и функциональностью.

Также стоит отметить моё желание попрактиковать моделирование и изготовление подвижной кисти для будущих проектов где подобная кисть, возможно, будет взаимодействовать с объектами реального мира.

Началась работа с моделирования кисти которая предполагала почти полное копирование подвижности человеческой кисти.

<img src="/imgs/renders/hand.jpg" width="600"/>

За сгибание и разгибание кисти отвечает система тросов, соединённая с комплектом сервоприводов в предплечье.

<img src="/imgs/renders/1.png" width="600"/>

Параллельно велась разработка предплечья и плечья копируя все основные двигательные функции человеческой руки.

<p>
  <img src="/imgs/renders/4.png" width="350"/>
  <img src="/imgs/renders/5.png" width="350"/>
</p>

<img src="/imgs/renders/2.png" width="700"/>

Так это выглядело на модели в сборе с платформой и центральной опорой

<img src="/imgs/renders/3.png" width="450"/>

Далее подбор и заказ подшипников и 3D-печать уже из более прочного PET-G пластика и сборка. Кстати, некоторые детали наружней оболочки кисти печатались из резиноподобного пластика FLEX.

<p>
  <img src="/imgs/photos/2_7.jpg" width="350"/>
  <img src="/imgs/photos/9.jpg" width="350"/>
  <img src="/imgs/photos/12.JPG" width="700"/>
</p>

_Промежуточный результат для теста кисти:_

<img src="/imgs/photos/2.png" width="700"/>

<img src="/imgs/video/hand2.gif" width="700"/>

#### Выводы по результатам теста кисти

Подвижност пальцев оставляла желать лучшего. Запястье смотрелось увереннее, но сервоприводы работали на пределе, что могло сказаться на долговечности узла. По итогам тестов было решено упростить конструкцию убрав из кисти все подвижные элементы, а для запястья поставить более сильные и надёжные приводы.

Как итог была взята всё та же 3D-модель кисти, но с залитыми подвижными сочленениями и распечатана одной деталью. В последствии была смоделирована новая версия кисти, не предполагающая подвижности.

Так выглядел робот на начало апреля 2021-го года

<img src="/imgs/photos/3.jpg" width="350"/>

*Репозиторий в работе... Далее в этом разделе расскажу про следующие версии руки и покажу записи с тестов уже всей руки*



<br/><br/><br/>

# Голова

Перед роботом стоят задачи локализации в пространстве, распознавания людей и их лиц, построения голосовой диалоговой системы, головой вращать и хорошо выглядеть. Для этих задач голова была укомплектована следующим образом:

Во-первых установлены три сервопривода что даёт возможность голове вращаться по трём ортогональным осям.

<img src="/imgs/renders/into_head.jpg" width="700"/>

Облако точек и цветное изображение роботу предоставляет 3D-камера Intel RealSense D455 со встроенным IMU-датчиком. 

<img src="/imgs/photos/d455.jpeg" width="500"/>

Голос пользователя робот снимает при помощи направленного микрофона Boya BY-MM1. Благодаря системе распознавания лиц и способности робота вращать головой по трём осям микрофон может быть направлен на лицо конкретного пользователя с целью дальнейшего снятия голоса. Такой подход позволяет ещё до процесса постобработки звука фильтровать шумы, не относящиеся к голосу пользователя.

<img src="/imgs/photos/mic.jpg" width="500"/>




<br/><br/><br/>

# Аппаратное обеспечение

Аппаратное обеспечеине робота можно логически поделить на несколько групп:
1. Блоки управления сервоприводами
2. Вычислительные модули

### Блоки управления сервоприводами

<p>
  <img src="/imgs/photos/2_22.jpg" width="600"/>
  <img src="/imgs/photos/2_4.jpg" width="265"/>
</p>

Работу всех сервоприводов робота обеспечивают два модуля: 
1. _Servo control unit_, который содержит в себе два контроллера Arduino Nano (один для рук, один для шеи), два шестнадцатиканальных драйвера сервоприводов, собственная плата питания и преобразователь напряжения для питания приводов шейного отдела.
2. _Converter unit_, в котором укомплектованы 6 преобразователей питания с максимальным выходным током до 9 ампер на каждом. Все преобразователи отрегулированы на разное напряжение в зависимости от питаемых ими приводов.

### Вычислительные модули

*Репозиторий в работе... Далее в этом разделе расскажу про все блоки в отдельности*



<br/><br/><br/>

# Оболочка

*Репозиторий в работе... Далее в этом разделе расскажу про дизайн робота и методы создания элементов обшивки*
