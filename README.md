# Человекоподобный клиент-сервисный робот / Humanoid service robot
<img src="/imgs/c1_2/druid2.png" width="800"/>

*01.07.2020 - 31.07.2021*  [![Generic badge](https://img.shields.io/badge/Status-Active-green.svg)](https://shields.io/)<br/>

<a name="team">*Команда/Team*</a>
1. [Андрей Недов](https://github.com/Andrey-Nedov-is-a-human)
- Лидер проекта
- Разработка аппаратного обеспечения
- Разработка конструкции
- Написание софта
- Менеджмент
- Медиапроизводство

2. [Алина Горбунова](https://www.instagram.com/xhirchx/)
- Разработка, моделирование и рендеринг дизайн-концепта
- Моделирование обшивки

3. [Алексей Абахтимов](https://github.com/AmazingRoovy)
- Разработка системы распознавания лиц
<br/>

Проект является моей [(Andrey-Nedov-is-a-human)](https://github.com/Andrey-Nedov-is-a-human) дипломной работой по окончании 4-го курса ИТ-факультета [Московского Политехнического Университета](https://new.mospolytech.ru/en/). Образовательная программа [киберфизические системы](https://old.mospolytech.ru/index.php?id=5318).

Научный руководитель [Идиатуллов Тимур Тофикович](https://old.mospolytech.ru/index.php?id=6714).

Финансирует проект компания [Диджитал Репаблик](https://di-re.ru/) с целью дальнейшего производства серии.

_! На странице много графики, анимаций, нужно время на полную загрузку_

## Содержание

1. [О проекте](#О-проекте)
2. [Платформа](#Платформа)
3. [Центральная опора](#Центральная-опора)
4. [Руки](#Руки)
5. [Голова](#Голова)
6. [Аппаратное обеспечение](#Аппаратное-обеспечение)
7. [Дизайн и оболочка](#Дизайн-и-оболочка)
8. [ПО робота](#ПО-робота)

# О проекте

[inst @druid_robotics](https://www.instagram.com/druid_robotics/)

<img src="/imgs/c1_2/1_2.jpg" width="800"/>
<!-- <p>
	<img src="/imgs/c1_2/10.jpg" width="400"/>
	<img src="/imgs/c1_2/11.jpg" width="400"/>
</p> -->

Проект посвящён разработке антропоморфного робота с функционалом промоутера, позволяющим роботу ориентироваться и безопасно перемещаться в социальных пространствах и взаимодействовать с людьми, выполняя задачи промоутинга и клиент-сервиса.

Предпосылкой для старта проекта стало активное развитие сегмента сервисной робототехники, нацеленной на взаимодействие робота с человеком. Всё чаще на задачи промоутинга и клиент-сервиса ставят роботов, в связи с чем на рынке робототехники образовалась слабо заполненная ниша. Проект призван наполнить данную нишу продуктом, решающим основные проблемы рынка и создать на нём конкурентную среду.

На текущем этапе своего развития Россия – это развивающаяся страна с высокообразованным населением, низкой стоимостью комплектующих, доступом к большому количеству различных поставщиков, что позволяет создавать роботов, конкурирующих на рынке с меньшими затратами.

На данный момент рынок сервисных роботов-промоутеров представлен такими компаниями как SoftBank Robotics с человекоподобным роботом Pepper, Promobot с их одноимённым роботом, роботом REEM от испанской компании PAL robotics и некоторых других игроков.

Учитывая недостатки конкурентов и появившиеся на рынке новые технологические решения для более эффективной работы с системами компьютерного зрения и машинного обучения, такие как Intel RealSense, Intel NUC, Intel Movidius предполагается, что есть хорошая возможность занять часть ниши на новом быстроразвивающемся рынке клиент-сервисной робототехники, создав антропоморфного робота-промоутера, в перспективе способного решать бизнес-задачи по обслуживанию клиентов.


# Платформа

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

Работа драйвера электродвигателя сопровождается выделением тепла, поэтому радиаторы драйверов двигателей нуждаются в дополнительном теплоотводе. Было принято решение создать систему охлаждения радиаторов.

<img src="/imgs/renders/platform/pl2_anim.gif" width="600"/> 

Необходимые детали были изготовлены при помощи 3D-печати, собраны и установлены в платформу. Для изготовления воздуховодов использовался пластик PLA. Также в систему охлаждения был установлен датчик температуры, который собирает информацию о температуре выходящего потока воздуха.

<img src="/imgs/photos/cool_s.png" width="600"/> 


## Состав компонентов 

В качестве основных двигателей были выбраны 60-ти ваттные двигатели постоянного тока с установленными на них червячными редукторами. Такая конструкция позволяет отвести корпус двигателей от внутренностей платформы освободив место для аккумулятора и других компонентов. С одной стороны червячные редукторы дают большое передаточное число, что сильно понижает сокрость и повышает момент на выходном валу. В нашем случае это очень кстати, ведь нашему роботу большие скорости ни к чему, а вот момент для того чтобы срываться с места очень нужен. С другой стороны червячные редукторы дают сильные потери энергии и не позволяют перетаскивать робота по поверхности.

В роли управляющего контроллера была использована плата _Arduino Mega 2560_ в связке с драйвером двигателей постоянного тока на базе чипа _L298_. Последняя схема может выдерживать ток до 15 апмер, значит наши нагрузки ей будут нипочём.

Дополнительное требование к платформе – возможность её использования независимо от тела робота. Такой подход не только даёт нам возможность отладки платформы на ранних стадиях разработки всего робота, но и использования платформы в других проектах. Для этого в системе платформы предусмотрен дополнительный одноплатный компьютер _Raspberry PI_, который может выступать в качестве управляющего блока, замены верхнему уровню робота.

Питается система от 12-ти вольтового свинцово-кислотного аккумуятора ёмкостью 26 Ампер-часов. Хватает на 5-6 часов активности.

## ПО платформы

Управлять платформой можно как с персонального компьютера, так и со смартфона. Причём никакого стороннего ПО для этого ставить не надо. 

Стоит только подключиться к wi-fi сети DRUID которую раздаёт сама платформа и в браузере перейти по специальному IP-адресу. Платформа сама загрузит вам пульт прямо в браузере.

<img src="/imgs/docs/pl_soft.png" width="700"/>

Система работает следующим образом. В платформе установлен wi-fi роутер, на котором развёрнута локальная сеть без доступа в интернет. Роутер перенаправляет запросы по специальному IP на порт сервера развёрнутого на Raspberry, который прослушивается HTTP сервером. Далее на устройство клиента скачивается пакет JS/HTML/CSS и медиа файлов, которые составляют пульт управления платформой. Фронт часть пульта адаптируется под соотношение сторон дисплея клиента и переключается между мобильной к десктопной версиями. Также веб-пульт поддерживает мультитач.

<p>
  <img src="/imgs/photos/1.png" width="200"/>
  <img src="/imgs/photos/1_1.png" width="550"/>
</p>

Как результат:

<img src="/imgs/video/works_360.gif" width="300"/>

## Съёмки промо

Для публикации в медиа съездили в DIY-магазни, закупили освещение, из дома взял камеру с линзами, отражатели и, в помещении финансирующей компании, отсняли небольшой проморолик по промежуточнуму результату.

[Youtube](https://www.youtube.com/watch?v=_gj3ynNgX4c)

<!-- <img src="/imgs/promo/promo3_480.gif" width="700"/> -->

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

Большое количество времени проекта ушло на разработку рук робота. Хронологически разработка кисти началась раньше разработки платоформы. Клиент-сервисному роботу руки нужны для жестикуляции во время общения с человеком. Вопрос насколько правдоподобно рука робота должна копировать подвижность человеческой на начало работы был открытым. В результате был пройден путь по упрощению конструкции до достижения баланса между простотой в изготовлении и функциональностью.

Также стоит отметить моё желание попрактиковать моделирование и изготовление подвижной кисти для будущих проектов где подобная кисть, возможно, будет взаимодействовать с объектами реального мира.

Началась работа с моделирования кисти которая предполагала почти полное копирование подвижности человеческой кисти.

<img src="/imgs/renders/hands.png" width="800"/>

Версия за версией прошло лето

<img src="/imgs/photos/old_hand 2.jpg" width="600"/>

И в итоге получилась такая кисть

<img src="/imgs/photos/2_8_2.jpg" width="700"/>

_Также отсняли небольшое промо для соцсетей_

[Youtube](https://www.youtube.com/watch?v=D9OtJSoRQ10)

<!-- <img src="/imgs/promo/hand_promo.gif" width="700"/>  -->

За сгибание и разгибание кисти отвечает система тросов, соединённая с комплектом сервоприводов в предплечье.

<img src="/imgs/renders/1.png" width="600"/>

Параллельно велась разработка предплечья и плеча копируя все основные двигательные функции человеческой руки.

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
  <img src="/imgs/photos/12_2.jpg" width="700"/>
</p>

_Промежуточный результат для теста кисти:_

<img src="/imgs/photos/2.png" width="700"/>

<img src="/imgs/video/hand2.gif" width="700"/>

#### Выводы по результатам теста кисти

Подвижность пальцев оставляла желать лучшего. Запястье смотрелось увереннее, но сервоприводы работали на пределе, что могло сказаться на долговечности узла. По итогам тестов было решено упростить конструкцию убрав из кисти все подвижные элементы, а для запястья поставить более сильные и надёжные приводы.

Как итог была взята всё та же 3D-модель кисти, но с залитыми подвижными сочленениями и распечатана одной деталью. В последствии была смоделирована новая версия кисти, не предполагающая подвижности.

Так выглядел робот на начало апреля 2021-го года

<img src="/imgs/photos/3.jpg" width="350"/>

### Упрощение конструкции руки

В итоге было решено что подвижность пальцев, как минимум в рабочем прототипе не обязательна. Была смоделирована своеобразная варежка, которой робот может вежливо указывать направление. В свою очередь в предплечье разместились более сильные приводы для запястья.

<img src="/imgs/renders/new_hand.jpg" width="700"/>

<img src="/imgs/renders/arms.png" width="700"/>

Далее была собрана вся рука целиком и протестирована вместе с аппаратным обеспечением, о котором расскажу в следующих разделах.

<img src="/imgs/renders/whole_new_hand.jpg" width="700"/>

_Тестируем правую руку:_

<img src="/imgs/video/mov360.gif" width="300"/>

_Текущий результат:_

<img src="/imgs/photos/full.jpg" width="400"/>

_Конструкция в работе..._


<br/><br/><br/>

# Голова

Перед роботом стоят задачи локализации в пространстве, распознавания людей и их лиц, ведения голосового диалога, а ещё головой вращать и хорошо выглядеть. Для этих задач голова была укомплектована следующим образом:

Во-первых установлены три сервопривода, что даёт возможность голове вращаться по трём ортогональным осям.

<img src="/imgs/renders/into_head.jpg" width="700"/>

Облако точек и цветное изображение роботу предоставляет 3D-камера Intel RealSense D455 со встроенным IMU-датчиком. 

<img src="/imgs/photos/d455.jpeg" width="400"/>

Голос пользователя робот снимает при помощи направленного микрофона Boya BY-MM1. Благодаря системе распознавания лиц и способности робота вращать головой по трём осям микрофон может быть направлен на лицо конкретного пользователя с целью дальнейшего снятия голоса. Такой подход позволяет ещё до процесса постобработки звука фильтровать шумы, не относящиеся к голосу пользователя.

<img src="/imgs/photos/mic.jpg" width="400"/>




<br/><br/><br/>

# Аппаратное обеспечение

Аппаратное обеспечеине робота можно логически поделить на несколько групп:
1. Блоки управления сервоприводами
2. Вычислительные модули

### Блоки управления сервоприводами

<img src="/imgs/renders/into_blocks.jpg" width="600"/>
<p>
  <img src="/imgs/photos/2_22.jpg" width="550"/>
  <img src="/imgs/photos/2_4.jpg" width="250"/>
</p>

Работу всех сервоприводов робота обеспечивают два модуля: 
1. _Servo control unit_, который содержит в себе два контроллера Arduino Nano (один для рук, один для шеи), два шестнадцатиканальных драйвера сервоприводов, собственная плата питания и преобразователь напряжения для питания приводов шейного отдела.
2. _Converter unit_, в котором укомплектованы 6 преобразователей питания с максимальным выходным током до 9 ампер на каждом. Все преобразователи отрегулированы на разное напряжение в зависимости от питаемых ими приводов.



### Вычислительные модули

Основной вычислительный блок представлен компактным компьютером iRU NUC 115 на базе Intel Core i5 c 16-ю гигабайтами оперативной памяти и процессорной графикой Intel Iris Plus Graphics 655.

<img src="/imgs/renders/pc.jpg" width="600"/>
<img src="/imgs/photos/2_23.jpg" width="600"/>

Для ускорения операций связанных с обработкой изображений дополнительно были закуплены два процессора машинного зрения (VPU) на базе архитектуры Intel Movidius Myriad X.

<img src="/imgs/photos/stick.jpeg" width="400"/>

*Репозиторий в работе... Далее в этом разделе расскажу про все блоки в отдельности*



<br/><br/><br/>

# Дизайн и оболочка

Стоит отметить, что конструкцию робота я заранее подгонял под параметры среднего взрослого мужского тела, по этому после обшивки робота оболочкой должен был получиться достаточно пропорциональный силует. 

_Конструкция робота без оболочки_

<img src="/imgs/renders/constr2.jpg" width="700"/>

### Дизайн-концепт

В начале второго семестра я закинул агитку на факультет дизайна Московского Политеха. Откликнулась очень талантливая и активная [Алина Горбунова](#team) с направления промышленного дизайна. Мы начали воплощать дизайн оболочки робота поверх уже имеющегося конструктива.

После многих встреч, долгих разговоров и десятков эскизов мы с [Алиной](#team) выработали видение дизайна робота, которое чуть позже было воплощено ей в дизайн-концепт.

<p>
	<img src="/imgs/sketches/sc2_2.jpg" width="200"/>
	<img src="/imgs/sketches/sc3_2.jpg" width="200"/>
</p>	

<p>
	<img src="/imgs/c1_2/2.jpg" width="400"/>
	<img src="/imgs/c1_2/3.jpg" width="430"/>
<!-- 	<img src="/imgs/c1_2/4.jpg" width="400"/>
	<img src="/imgs/c1_2/5.jpg" width="400"/> -->
</p>

<img src="/imgs/c1_2/10_2.jpg" width="700"/>
<img src="/imgs/c1_2/11_2.jpg" width="700"/>

<p>
	<img src="/imgs/c1_2/6.jpg" width="300"/>
	<img src="/imgs/c1_2/7.jpg" width="350"/>
</p>

<img src="/imgs/c1_2/9.jpg" width="700"/>
<img src="/imgs/c1_2/8.jpg" width="700"/>



<!--	<img src="/imgs/c1/6.jpg" width="300"/>
	<img src="/imgs/c1/4.jpg" width="200"/>
	<img src="/imgs/c1/c1_1_full-hd.png" width="900"/>
	<img src="/imgs/c1/vot.png" width="900"/>  -->


### Оболочка

Далее стояла задача создать из смоделированных дизайнером поверхностей оболочки детали пригодные для вакуумной формовки. Тут уже работал я, совмещая поверхности с конструктивом, чтобы можно было ещё и собрать это всё.

_Оболочка готова к изготовлению_

<img src="/imgs/renders/cover_on.jpg" width="700"/>

_DRUID в реальном цвете_

<img src="/imgs/renders/cover_on2.jpg" width="700"/>




<br/><br/><br/>

# ПО робота

Программное обеспечение робота, естественно, должно разрабатываться непрерывно. Добовление нового функционала, исправление ошибок. 
Чтобы начать написание ПО нужно понимать чего мы хотим, и к какому сроку. Поскольку сроки на этот MVP, прямо скажем, поджимают, в качестве программы минимум было решено реализовать движение робота с обходом препятствий, ориентируясь на данные с 3D-камеры.

В качестве основы для операционной системы робота было решено использовать ROS версии Noetic.

_Архитектура системы:_

<img src="/imgs/docs/OS.png" width="600"/>

Главный блок принятия решений и roscore запускаются на главном вычислительном блоке iRU NUC 115. К центральному устройству подключены четыре платы Arduino, две от платформы, отвечают за управление моторами и сбор информации с сенсоров, и две от туловища, для упраления приводами рук и шеи. 

Чтобы с чего-то начать пока робот ещё не собран, поставил пакет TurtleBot3 и, в симуляторе Gazebo, запустил модель робота Bruger, оснащённого лучевым 2D-лидаром, чтобы на его примере отработать простой алгоритм обхода препятствий.

Далее написал создал пакет control с нодой cmd.py цель которой не дать роботу столкнуться с препятствием во время движения. Стоит отметить что подобная нода уже реализована в пакете, написана на С++. Я написал и использовал свою ноду на питоне, скрипт [по ссылке](https://github.com/Andrey-Nedov-is-a-human/DRUID-humanoid-robot/blob/main/imgs/software/ws/src/control/src/cmd.py).

Сконфигурировал URDF-файл по которому робот, в пространстве rviz, будет представлять из себя зелёный куб, а на поверхность мира будут нанесены данные с лидара.

_URDF-разметка конфигурации робота_
```xml
<?xml version="1.0" ?>
<robot name="green_box" xmlns:xacro="http://www.ros.org/wiki/xacro">
	<link name="base_link">
	    <visual>
		<origin rpy="0 0 0" xyz="0 0 0.3"/>
		<geometry>
			<box size="0.5 0.5 0.5"/>
		</geometry>
		<material name="green">
    			<color rgba="0.1 1.0 0.1 1.0"/>
  		</material>
	    </visual>
	</link>
	<joint name="base_joint2" type="fixed">
		<parent link="base_link"/>
		<child link="base_scan"/>	 
	</joint>
	<link name="base_scan">
	</link>
</robot>
```

_launch-файл_
```HTML
<launch>
	<param name="robot_description" command="cat $(find control)/urdf/turt_model.urdf" />
	<node pkg="control" type="cmd.py" name = "cmd1" output ="screen"/>
</launch>
```

_Результат_

<img src="/imgs/renders/bot.gif" width="800"/>

Хорошо, вроде бы простейшая логика работы у нас уже есть, дальше я подключил Intel RealSense D455, интегрировал его в ROS и получил с него облако точек.

_Облако точек с D455 в rviz:_

<img src="/imgs/renders/cam.gif" width="700"/>

Таким образом совмещая два этих блока, когда робот будет готов, мы сможем быстро решить на нём задачу движения с обходом препятствий.
 
### Detectron2

Так же много экспериментов проводилось с _Detectron2_. Сначала я ставил проект и обрабатывал отдельные изображения тремя предобученными сетями, две реализуют instance segmentation - поиск, классификация и выделение маски знакомых объектов, и panoptic segmentation - сеть пытается отнести кажый пиксель изображения к какому-либо знакомому классу. Третья сеть делает предикт ключевых точек на теле изображенного человека.

<p>
 <img src="/imgs/software/2.jpg" width="400"/>
 <img src="/imgs/software/5.jpg" width="200"/>
 <img src="/imgs/software/7.jpg" width="200"/>
</p>

<p>
 <img src="/imgs/software/3.jpg" width="400"/>
 <img src="/imgs/software/8.jpg" width="200"/>
 <img src="/imgs/software/9.jpg" width="200"/>
</p>

<p>
 <img src="/imgs/software/1.jpg" width="400"/>
 <img src="/imgs/software/4.jpg" width="200"/>
 <img src="/imgs/software/6.jpg" width="200"/>
</p>

Далее написал скрипт для работы Detectron2 в реалтайме.

<p>
 <img src="/imgs/software/1.png" width="300"/>
 <img src="/imgs/software/2.png" width="300"/>
</p>

<p>
 <img src="/imgs/software/3.png" width="300"/>
 <img src="/imgs/software/4.png" width="300"/>
</p>

Записи не сохранилось, как и самой системы, только кадры. Система оказалась слишком прожорливая для нашего железа и выдавала максимум 2-3 fps.

Было решено отказаться от Detectron2 и искать более специализированные менее ресурсоёмкие технологии.

Сейчас мы открываем для себя большое количество софта от Intel оптимизированного под их аппаратные платформы Intel NUC, Intel RealSense, Intel Movidius, наш робот, напоминаю, оснащён всеми этими устройствами. Заявленая эффективность такого решения впечатляет, сейчас разбираемся с их инфраструктурой.

<br>
<br>

### Система распознавания ключевых точек на теле человека

Для распознавания ключевых точек вместо тяжелого Detectron2 я использовал технологию [Intel Skeleton Tracking](https://www.intelrealsense.com/skeleton-tracking/), оптимизированную под Intel NUC и Intel RealSense, которую можно ещё и ускорить, добавив дополнительные вычислительные ядра в Intel Neural Compute Stick 2. Как будет применена технология в нашем проекте и будет ли она применена вообще я ещё не знаю, но не опробовать её, имея на руках 3D-камеру и всё сопутствующее аппаратное обеспечение, я не могу.

_Демо работы системы распознавания ключевых точек Intel NUC 115 + RealSense D455:_

<img src="/imgs/video/key.gif" width="700"/>

Замечание: изображение является проекцией трёхмерного облака точек, а чёрные области - это зоны недоступные для расчёта глубины ввиду или слишком маленького расстояния до камеры, или того что зона находится за другим объектом.

Как можно заметить система работает хорошо и бодро, 13-16 fps стабильно. 

Чуть позже попробую всё это дело ускорить при помощи Intel Neural Compute Stick 2.

<br>
<br>

### Система распознавания лиц

Так же было решено опробовать различные технологии распознавания лиц чтобы робот, как минимум, мог направлять голову в сторону лица человека.

_Первая демка от [Алексея Абахтимова](#team) по системе распознавания лиц:_

 <img src="/imgs/software/face.gif" width="700"/>
 
Алексей провёл анализ различных технологий в поисках наиболее точной и ресурсоэффективной. 
Использовалалсь библиотека Dlib. Запускалась на ноутбуке с Intel Core i5-8256U, 8 Гб RAM и Intel UHD Graphics 620.


*Репозиторий в работе...* 
