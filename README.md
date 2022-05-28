# Humanoid service robot
<img src="/imgs/c1_2/druid2.png" width="800"/>

<!-- *01.07.2020 - 31.07.2021*   -->
[![Generic badge](https://img.shields.io/badge/Status-Frozen-blue.svg)](https://shields.io/)<br/>

<a name="team">*The team*</a>
1. [Andrey Nedov](https://github.com/Andrey-Nedov)
- CTO
- Software developmer
- Hardware developmer 
- Mechanical/CAD engineer

2. [Alina Gorbunova](https://www.instagram.com/xhirchx/)
- Robot shell designer


<!-- Проект посвящён разработке антропоморфного робота с функционалом промоутера, позволяющим роботу ориентироваться и безопасно перемещаться в социальном пространстве и взаимодействовать с людьми, выполняя задачи промоутинга и клиент-сервиса. -->
<br>
This project is dedicated to the development of an anthropomorphic robot with the functionality of a promoter, which allows the robot to navigate and move safely in social space and interact with people, performing the tasks of promotion and customer service.

<!-- Финансирует проект компания [Диджитал Репаблик](https://di-re.ru/) с целью дальнейшего производства серии. -->

The project is financed by the Digital Republic company for further production.

<!-- _! На странице много графики, анимаций, нужно время на полную загрузку_ -->

## Сontents

1. [About the project](#About-the-project)
2. [Platform](#Platform)
3. [Main support](#Main-support)
4. [Hands](#Hand)
5. [Head](#Head)
6. [Hardware](#Hardware)
7. [Design and robot shell](#Design-and-robot-shell)
8. [Software](#Software)

# About the project

[inst @druid_robotics](https://www.instagram.com/druid_robotics/)

<img src="/imgs/c1_2/1_2.jpg" width="800"/>
<!-- <p>
	<img src="/imgs/c1_2/10.jpg" width="400"/>
	<img src="/imgs/c1_2/11.jpg" width="400"/>
</p> -->

<!-- Предпосылкой для старта проекта стало активное развитие сегмента сервисной робототехники, нацеленной на взаимодействие робота с человеком. Всё чаще на задачи промоутинга и клиент-сервиса ставят роботов, в связи с чем на рынке робототехники образовалась слабо заполненная ниша. Проект призван наполнить данную нишу продуктом, решающим основные проблемы рынка и создать на нём конкурентную среду. -->

The prerequisite for the start of this project was the active expansion of the segment of service robotics, aimed at the interaction of a robot with people. Increasingly, robots are assigned to the tasks of promotion and customer service, and therefore a poorly filled space has formed in the robotics market. The project is designed to fill this space with a product that solves the main problems of the market and creates a competitive environment on it.

<!-- Учитывая недостатки конкурентов и появившиеся на рынке новые технологические решения для более эффективной работы с системами компьютерного зрения и машинного обучения, такие как Intel RealSense, Intel NUC, Intel Movidius предполагается, что есть хорошая возможность занять часть ниши на новом быстроразвивающемся рынке клиент-сервисной робототехники, создав антропоморфного робота-промоутера, в перспективе способного решать бизнес-задачи по обслуживанию клиентов. -->

Given the shortcomings of competitors and new technological solutions that have appeared on the market for more efficient work with computer vision and machine learning systems, such as Intel RealSense, Intel NUC, Intel Movidius, it is assumed that there is a good opportunity to take part in a niche in the new fast-growing market for client service robotics, by creating an anthropomorphic robot-promoter, capable of solving customer service business problems in the future.


# Platform

<img src="/imgs/photos/2_3_1500.jpg" width="600"/>

## Platform configuration

<!-- Для передвижения робот использует подвижную платформу, которая реализует схему трипода на омни-колесах. Такой подход, обеспечивая голономность системы, позволяет платформе, не совершая разворотов вокруг вертикальной оси, перемещаться в плоскости по любой заданной траектории. -->

For movement, the robot uses a movable platform that implements a tripod scheme on omni-wheels. This approach, ensuring the holonomy of the system, allows the platform to move in the plane along any given trajectory without making turns around the vertical axis.

<img src="/imgs/docs/result_vect.png" width="600"/>

<!-- Результирующий вектор направления рассчитывается путём суммирования трёх векторов перемещения колёс платформы. Тогда управляющий сигнал для двигателей, нормированный в диапазоне от 0 до 255, будет рассчитываться как функция синуса от разницы полярного угла результирующего вектора и угла установки омни-колеса. -->

The resulting direction vector is calculated by summing the three displacement vectors of the platform wheels. Then the control signal for the engines, normalized in the range from 0 to 255, will be calculated as a function of the sine of the difference between the polar angle of the resulting vector and the angle of the omni-wheel.


## Platform frame modeling

The frame was modeled in Autodesk Inventor.

<img src="/imgs/renders/platform/pl1_anim.gif" width="600"/>

<p>
  <img src="/imgs/docs/frame.jpg" width="260"/>
  <img src="/imgs/docs/plate.png" width="240"/>
  <img src="/imgs/docs/motor.png" width="220"/>
  <img src="/imgs/docs/motor_f.png" width="120"/>
</p>

<!-- Основой конструкции платформы робота является рама из стального профиля толщиной 20 мм. 
Рама создавалась методами резки и сварки металла и смоделирована таким образом, чтобы все компоненты платформы могли быть помещены внутрь неё. Частично вынесены наружу были только двигатели из-за их крупных габаритов. Пластиковые крышки вырезались на лазерном ЧПУ-станке. -->

The basis of the design of the robot platform is a frame made of a steel profile 20 mm thick.
The frame was created by cutting and welding metal and modeled in such a way that all platform components can be placed inside it. Only the engines were partially taken out because of their large dimensions. Plastic covers were cut on a CNC laser machine.

<!-- К раме прикреплены стальные пластины толщиной 4 мм, вырезанные на плазменной установке с ЧПУ, которые являются опорой для двигателей. Сталь такой толщины позволяет платформе выдерживать большие нагрузки, избегая деформаций. -->

Attached to the frame are 4mm thick CNC plasma-cut steel plates that support the motors. Steel of this thickness allows the platform to withstand heavy loads, avoiding deformations.

<img src="/imgs/photos/2_3_1501.JPG" width="600"/> 

### Cooling system

<!-- Работа драйвера электродвигателя сопровождается выделением тепла, поэтому радиаторы драйверов двигателей нуждаются в дополнительном теплоотводе. Было принято решение создать систему охлаждения радиаторов. -->

The operation of the motor driver is accompanied by the release of heat, so the radiators of the motor drivers need an additional heat sink. It was decided to create a cooling system for radiators.

<img src="/imgs/renders/platform/pl2_anim.gif" width="600"/> 

<!-- Необходимые детали были изготовлены при помощи 3D-печати, собраны и установлены в платформу. Для изготовления воздуховодов использовался пластик PLA. Также в систему охлаждения был установлен датчик температуры, который собирает информацию о температуре выходящего потока воздуха. -->

The necessary parts were made using 3D printing, assembled and installed on the platform. For the manufacture of air ducts, PLA plastic was used. Also, a temperature sensor was installed in the cooling system, which collects information about the temperature of the outgoing air stream.

<img src="/imgs/photos/cool_s.png" width="600"/> 


## Low-level components 

<!-- В качестве основных двигателей были выбраны 60-ти ваттные двигатели постоянного тока с установленными на них червячными редукторами. Такая конструкция позволяет отвести корпус двигателей от внутренностей платформы освободив место для аккумулятора и других компонентов. С одной стороны червячные редукторы дают большое передаточное число, что сильно понижает сокрость и повышает момент на выходном валу. В нашем случае это очень кстати, ведь нашему роботу большие скорости ни к чему, а вот момент для того чтобы срываться с места очень нужен. С другой стороны червячные редукторы дают сильные потери энергии и не позволяют перетаскивать робота по поверхности. -->

As the main motors, 60-watt DC motors with worm gears installed on them were chosen. This design allows the engine body to be pulled away from the platform's innards, making room for the battery and other components. On the one hand, worm gears give a large gear ratio, which greatly reduces the speed and increases the torque on the output shaft. In our case, this is very useful, because our robot does not need high speeds, but the moment to take off is very necessary. On the other hand, worm gears give strong energy losses and do not allow dragging the robot over the surface.

<!-- В роли управляющего контроллера была использована плата _Arduino Mega 2560_ в связке с драйвером двигателей постоянного тока на базе чипа _L298_. Последняя схема может выдерживать ток до 15 апмер, значит наши нагрузки ей будут нипочём. -->

The _Arduino Mega 2560_ board was used as a controller with a DC motor driver based on the _L298_ chip. The last circuit can withstand a current of up to 15 amps, which means that our loads will be nothing to it.

<!-- Дополнительное требование к платформе – возможность её использования независимо от тела робота. Такой подход не только даёт нам возможность отладки платформы на ранних стадиях разработки всего робота, но и использования платформы в других проектах. Для этого в системе платформы предусмотрен дополнительный одноплатный компьютер _Raspberry PI_, который может выступать в качестве управляющего блока, замены верхнему уровню робота. -->

An additional requirement for the platform is the ability to use it regardless of the robot body. This approach not only gives us the opportunity to debug the platform in the early stages of development of the entire robot, but also to use the platform in other projects. To do this, the platform system provides an additional single-board computer _Raspberry PI_, which can work as a control unit, replacing the upper level of the robot.

<!-- Питается система от 12-ти вольтового свинцово-кислотного аккумуятора ёмкостью 26 Ампер-часов. Хватает на 5-6 часов активности. -->

The system is powered by a 12-volt lead-acid battery with a capacity of 26 Ah. Enough for 5-6 hours of activity.

## Software

<!-- Управлять платформой можно как с персонального компьютера, так и со смартфона. Причём никакого стороннего ПО для этого ставить не надо. Стоит только подключиться к wi-fi сети DRUID которую раздаёт сама платформа и в браузере перейти по специальному IP-адресу. Платформа сама загрузит вам пульт прямо в браузере. -->

The platform can be controlled both from a personal computer and from a smartphone. And you don’t need to install any third-party software for this. One has only to connect to the DRUID wi-fi network, which is distributed by the platform itself, and go to a special IP address in the browser. The platform itself will download the remote control directly in the browser.

<img src="/imgs/docs/pl_soft.png" width="700"/>

<!-- Система работает следующим образом. В платформе установлен wi-fi роутер, на котором развёрнута локальная сеть без доступа в интернет. Роутер перенаправляет запросы по специальному IP на порт сервера развёрнутого на Raspberry, который прослушивается HTTP сервером. Далее на устройство клиента скачивается пакет JS/HTML/CSS и медиа файлов, которые составляют пульт управления платформой. Фронт часть пульта адаптируется под соотношение сторон дисплея клиента и переключается между мобильной к десктопной версиями. Также веб-пульт поддерживает мультитач. -->

The system works as follows. The platform has a wi-fi router on which a local network is deployed without Internet access. The router forwards requests on a specific IP to the port of the server deployed on the Raspberry, which is listening on the HTTP server. Next, a package of JS/HTML/CSS and media files that make up the platform control panel is downloaded to the client's device. The front part of the remote adapts to the aspect ratio of the client's display and switches between mobile and desktop orientation. The web-remote also supports multi-touch.

<p>
  <img src="/imgs/photos/1.png" width="200"/>
  <img src="/imgs/photos/1_1.png" width="550"/>
</p>

Result:

<img src="/imgs/video/works_360.gif" width="300"/>

## Promo video

<!-- Для публикации в медиа съездили в DIY-магазни, закупили освещение, из дома взял камеру с линзами, отражатели и, в помещении финансирующей компании, отсняли небольшой проморолик по промежуточнуму результату. -->

For publication in the media, we went to a DIY store, bought lighting, took a camera with lenses, reflectors from home and, in the premises of a financing company, filmed a small promo video on the intermediate result.

[Youtube](https://www.youtube.com/watch?v=_gj3ynNgX4c)

<!-- <img src="/imgs/promo/promo3_480.gif" width="700"/> -->

<!-- Чтобы добиться от робота плавных движений использовал синусоидальные функции эксперементируя с фазами. Кстати, весь съёмочный день, это часов 5-6, робот катался без подзарядки. -->

To achieve smooth movements from the robot, I used sinusoidal functions experimenting with phases. By the way, the whole shooting day, it's 5-6 hours, the robot rode without recharging.

<br/><br/><br/>

# Main support

<!-- Центральная опора робота выполняет роль каркаса для всех компонентов системы аниматроники. Она выполнена из стального профиля толщиной 20мм методами резки и сварки металла, что обеспечивает прочность конструкции.  -->

The main support of the robot works as a frame for all components of the animatronics system. It is made of a steel profile 20mm thick by cutting and welding metal, which ensures the strength of the structure.

<img src="/imgs/renders/support.jpg" width="760"/>

<!-- Для соединения отдельных частей опоры между собой, крепления опоры к платформе и установки оборудования используются болтовые соединения с самоконтрящимися гайками. По всей поверхности опоры были просверлены дополнительные отверстия для крепления компонентов системы аниматроники. -->

Bolted connections with self-locking nuts are used to connect the individual parts of the support to each other, fasten the support to the platform and install the equipment. Additional holes were drilled over the entire surface of the support for attaching the components of the animatronic system.

<!-- Для крепления опоры к платформе используется всего три болта, для крепления рук, используется по одному болту на каждую руку -->

To attach the support to the platform, only three bolts are used, for attaching the arms, one bolt is used for each arm

<p>
  <img src="/imgs/photos/8.jpg" width="250"/>
  <img src="/imgs/photos/7.jpg" width="250"/>
</p>


<br/><br/><br/>

# Hands

<img src="/imgs/photos/2_6_1500.jpg" width="700"/>

<!-- Большое количество времени проекта ушло на разработку рук робота. Хронологически разработка кисти началась раньше разработки платоформы. Клиент-сервисному роботу руки нужны для жестикуляции во время общения с человеком. Вопрос насколько правдоподобно рука робота должна копировать подвижность человеческой на начало работы был открытым. В результате был пройден путь по упрощению конструкции до достижения баланса между простотой в изготовлении и функциональностью. -->

A lot of the project's time was spent on developing the robot's arms. Chronologically, the development of the brush began before the development of the platform. The client-service robot needs hands to gesticulate while communicating with a person. The question of how plausible the robot's hand should copy the mobility of a human at the beginning of work was open. As a result, a path has been taken to simplify the design to achieve a balance between ease of manufacture and functionality.

<!-- Также стоит отметить моё желание попрактиковать моделирование и изготовление подвижной кисти для будущих проектов где подобная кисть, возможно, будет взаимодействовать с объектами реального мира. -->

There was also a great desire to practice modeling and making a movable hand for future projects.

<!-- Началась работа с моделирования кисти которая предполагала почти полное копирование подвижности человеческой кисти. -->

Work began with the modeling of the hand, which assumed almost complete copying of the mobility of the human hand.

<img src="/imgs/renders/hands.png" width="800"/>

<!-- Версия за версией прошло лето -->

Summer passed in experiments

<img src="/imgs/photos/old_hand 2.jpg" width="600"/>

<!-- И в итоге получилась такая кисть -->

And in the end it turned out such a hand

<img src="/imgs/photos/2_8_2.jpg" width="700"/>

<!-- _Также отсняли небольшое промо для соцсетей_ -->

_Also filmed a small promo for social networks_

[Youtube](https://www.youtube.com/watch?v=D9OtJSoRQ10)

<!-- <img src="/imgs/promo/hand_promo.gif" width="700"/>  -->

<!-- За сгибание и разгибание кисти отвечает система тросов, соединённая с комплектом сервоприводов в предплечье. -->

Flexion and extension of the hand is controlled by a cable system connected to a set of servo drives in the forearm.

<img src="/imgs/renders/1.png" width="600"/>

<!-- Параллельно велась разработка предплечья и плеча копируя все основные двигательные функции человеческой руки. -->

In parallel, the development of the forearm and shoulder was carried out, copying all the main motor functions of the human hand.

<p>
  <img src="/imgs/renders/4.png" width="350"/>
  <img src="/imgs/renders/5.png" width="350"/>
</p>

<img src="/imgs/renders/2.png" width="700"/>

<!-- Так это выглядело на модели в сборе с платформой и центральной опорой -->

This is how it looked on the model assembled with a platform and a main support

<img src="/imgs/renders/3.png" width="450"/>

<!-- Далее подбор и заказ подшипников и 3D-печать уже из более прочного PET-G пластика и сборка. Кстати, некоторые детали наружней оболочки кисти печатались из резиноподобного пластика FLEX -->

Further, the selection and ordering of bearings and 3D printing from more durable PET-G plastic and assembly. By the way, some details of the outer shell of the brush were printed from rubber-like FLEX plastic.
 
<p>
  <img src="/imgs/photos/2_7.jpg" width="350"/>
  <img src="/imgs/photos/9.jpg" width="350"/>
  <img src="/imgs/photos/12_2.jpg" width="700"/>
</p>

<!-- _Промежуточный результат для теста кисти:_ -->

_Intermediate result for brush test:_

<img src="/imgs/photos/2.png" width="700"/>

<img src="/imgs/video/hand2.gif" width="700"/>

#### Conclusions from the hand test results

<!-- Подвижность пальцев оставляла желать лучшего. Запястье смотрелось увереннее, но сервоприводы работали на пределе, что могло сказаться на долговечности узла. По итогам тестов было решено упростить конструкцию убрав из кисти все подвижные элементы, а для запястья поставить более сильные и надёжные приводы. -->

The mobility of the fingers was bad. The wrist looked more confident, but the servos were working to the limit, which could affect the durability of the knot. Based on the results of the tests, it was decided to simplify the design by removing all moving elements from the hand, and to put stronger and more reliable drives for the wrist.

<!-- Как итог была взята всё та же 3D-модель кисти, но с залитыми подвижными сочленениями и распечатана одной деталью. В последствии была смоделирована новая версия кисти, не предполагающая подвижности. -->

As a result, the same 3D model of the brush was taken, but with filled movable joints and printed in one piece. Subsequently, a new version of the hand was modeled, which does not suppose mobility.

<!-- Так выглядел робот на начало апреля 2021-го года -->

This is what the robot looked like at the beginning of April 2021

<img src="/imgs/photos/3.jpg" width="350"/>

### Simplification of the design of the hand

<!-- В итоге было решено что подвижность пальцев, как минимум в рабочем прототипе не обязательна. Была смоделирована своеобразная варежка, которой робот может вежливо указывать направление. В свою очередь в предплечье разместились более сильные приводы для запястья. -->

As a result, it was decided that the mobility of the fingers, at least in the working prototype, is not necessary. A kind of mitten was modeled, with which the robot can politely indicate the direction. In turn, stronger drives for the wrist were located in the forearm.

<img src="/imgs/renders/new_hand.jpg" width="700"/>

<img src="/imgs/renders/arms.png" width="700"/>

<!-- Далее была собрана вся рука целиком и протестирована вместе с аппаратным обеспечением, о котором расскажу в следующих разделах. -->

Next, the whole arm was assembled and tested along with the hardware, which I will discuss in the following sections.

<img src="/imgs/renders/whole_new_hand.jpg" width="700"/>

<!-- _Тестирую правую руку:_ -->

_Testing the right hand:_

<img src="/imgs/video/mov360.gif" width="300"/>

<!-- _Текущий результат:_ -->

_Current result:_

<img src="/imgs/photos/full.jpg" width="400"/>

<!-- _Конструкция в работе..._ -->

_Design in progress..._


<br/><br/><br/>

# Head

<!-- Перед роботом стоят задачи локализации в пространстве, распознавания людей и их лиц, ведения голосового диалога, а ещё головой вращать и хорошо выглядеть. Для этих задач голова была укомплектована следующим образом: -->

The robot will have to deal with the task of localization in space, recognizing people and their faces, conducting a voice dialogue, and also rotating its head and looking good. For these tasks, the head was equipped as follows:

<!-- Во-первых установлены три сервопривода, что даёт возможность голове вращаться по трём ортогональным осям. -->

Firstly, three servos are installed, which makes it possible for the head to rotate along three orthogonal axes.

<img src="/imgs/renders/into_head.jpg" width="700"/>

<!-- Облако точек и цветное изображение роботу предоставляет 3D-камера Intel RealSense D455 со встроенным IMU-датчиком.  -->

The point cloud and color image are provided to the robot by the Intel RealSense D455 3D camera with an integrated IMU sensor.

<img src="/imgs/photos/d455.jpeg" width="400"/>

<!-- Голос пользователя робот снимает при помощи направленного микрофона Boya BY-MM1. Благодаря системе распознавания лиц и способности робота вращать головой по трём осям микрофон может быть направлен на лицо конкретного пользователя с целью дальнейшего снятия голоса. Такой подход позволяет ещё до процесса постобработки звука фильтровать шумы, не относящиеся к голосу пользователя. -->

The robot picks up the user's voice using the Boya BY-MM1 directional microphone. Thanks to the facial recognition system and the ability of the robot to rotate its head along three axes, the microphone can be directed to the face of a specific user in order to further pick up the voice. This approach allows you to filter out noise that is not related to the user's voice even before the audio post-processing process.

<img src="/imgs/photos/mic.jpg" width="400"/>




<br/><br/><br/>

# Hardware

<!-- Аппаратное обеспечеине робота можно логически поделить на несколько групп:
1. Блоки управления сервоприводами
2. Вычислительные модули -->

Robot hardware can be logically divided into several groups:
1. Servo motors control units
2. Computing units

### Servo motors control units

<img src="/imgs/renders/into_blocks.jpg" width="600"/>
<p>
  <img src="/imgs/photos/2_22.jpg" width="550"/>
  <img src="/imgs/photos/2_4.jpg" width="250"/>
</p>

<!-- Работу всех сервоприводов робота обеспечивают два модуля: 
1. _Servo control unit_, который содержит в себе два контроллера Arduino Nano (один для рук, один для шеи), два шестнадцатиканальных драйвера сервоприводов, собственная плата питания и преобразователь напряжения для питания приводов шейного отдела.
2. _Converter unit_, в котором укомплектованы 6 преобразователей питания с максимальным выходным током до 9 ампер на каждом. Все преобразователи отрегулированы на разное напряжение в зависимости от питаемых ими приводов. -->

The operation of all robot servos is provided by two modules:
1. _Servo motor control unit_, which contains two Arduino Nano controllers (one for the arms, one for the neck), two sixteen-channel servo drivers, its own power board and a voltage converter to power the neck drives.
2. _Converter unit_, which is equipped with 6 power converters with a maximum output current of up to 9 amperes each. All converters are adjusted to different voltages depending on the drives they feed.



### Computing units

<!-- Основной вычислительный блок представлен компактным компьютером iRU NUC 115 на базе Intel Core i5 c 16-ю гигабайтами оперативной памяти и процессорной графикой Intel Iris Plus Graphics 655. -->

The main computing unit is represented by a compact iRU NUC 115 computer based on Intel Core i5 with 16 gigabytes of RAM and Intel Iris Plus Graphics 655 processor graphics.

<img src="/imgs/renders/pc.jpg" width="600"/>
<img src="/imgs/photos/2_23.jpg" width="600"/>

<!-- Для ускорения операций обработки изображений дополнительно были закуплены два процессора машинного зрения (VPU) на базе архитектуры Intel Movidius Myriad X. -->

To speed up image processing operations, two additional machine vision processors (VPUs) based on the Intel Movidius Myriad X architecture were purchased.

<img src="/imgs/photos/stick.jpeg" width="400"/>

<!-- *Репозиторий в работе... Далее в этом разделе расскажу про все блоки в отдельности* -->

*Repository in progress... Further in this section I will talk about all the blocks separately*



<br/><br/><br/>

# Design and robot shell

<!-- Стоит отметить, что конструкцию робота я заранее подгонял под параметры среднего взрослого мужского тела, по этому после обшивки робота оболочкой должен был получиться достаточно пропорциональный силует.  -->

The design of the robot was adjusted in advance to the parameters of an average adult male body, so after covering the robot with a shell, a fairly proportional silhouette should have been obtained.

<!-- _Конструкция робота без оболочки_ -->

_Robot design without shell_

<img src="/imgs/renders/constr2.jpg" width="700"/>

### Design-concept

<!-- После многих встреч, долгих разговоров и десятков эскизов мы с [Алиной](#team) выработали видение дизайна робота, которое чуть позже было воплощено ей в дизайн-концепт. -->

<!-- Было выработанно видение дизайна робота, которое чуть позже было воплощено в дизайн-концепт. -->

A vision of the design of the robot was developed, which was later embodied in a design concept.

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


### Shell

<!-- Далее стояла задача создать из смоделированных дизайнером поверхностей оболочки детали пригодные для вакуумной формовки. Тут уже работал я, совмещая поверхности с конструктивом, чтобы можно было ещё и собрать это всё. -->

The next task was to create parts suitable for vacuum molding from the shell surfaces modeled by the designer. It was necessary to combine the surfaces with the structure, so that it was possible to assemble it all.

<!-- _Оболочка готова к изготовлению_ -->

_ Shell is ready for production _

<img src="/imgs/renders/cover_on.jpg" width="700"/>

<!-- _DRUID в реальном цвете_ -->

_DRUID in real color_

<img src="/imgs/renders/cover_on2.jpg" width="700"/>




<br/><br/><br/>

# Software

<!-- Программное обеспечение робота, естественно, должно разрабатываться непрерывно. Добовление нового функционала, исправление ошибок. 
Чтобы начать написание ПО нужно понимать чего мы хотим, и к какому сроку. Поскольку сроки на этот MVP, прямо скажем, поджимают, в качестве программы минимум было решено реализовать примитивную логику движения робота с обходом препятствий (пока без локализации и планирования пути) ориентируясь на данные с 3D-камеры. -->

The software of the robot, of course, must be developed continuously. Adding new functionality, fixing bugs.
To start writing software, you need to understand what we want, and by what date. Since the deadlines for this MVP, frankly, are running out, as a minimum program, it was decided to implement the primitive logic of the robot’s movement with obstacle avoidance (so far without localization and path planning) based on data from a 3D camera.

<!-- В качестве основы для операционной системы робота было решено использовать ROS версии Noetic. -->

As a basis for the operating system of the robot, it was decided to use the ROS version of Noetic.

<!-- _Архитектура системы:_ -->

<!-- _System architecture:_

<img src="/imgs/docs/OS.png" width="600"/> -->

<!-- Главный блок принятия решений и roscore запускаются на главном вычислительном блоке iRU NUC 115. К центральному устройству подключены четыре платы Arduino, две от платформы, отвечают за управление моторами и сбор информации с сенсоров, и две от туловища, для упраления приводами рук и шеи. 

Чтобы с чего-то начать пока робот ещё не собран, поставил пакет TurtleBot3 и, в симуляторе Gazebo, запустил модель робота Bruger, оснащённого лучевым 2D-лидаром, чтобы на его примере отработать простой алгоритм обхода препятствий.

Далее написал создал пакет control с нодой cmd.py цель которой не дать роботу столкнуться с препятствием во время движения. 

Стоит отметить что подобная нода уже реализована в пакете, написана на С++. Я написал и использовал свою ноду на питоне, скрипт [по ссылке](https://github.com/Andrey-Nedov-is-a-human/DRUID-humanoid-robot/blob/main/imgs/software/ws/src/control/src/cmd.py).

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
--> 
### Detectron2

<!-- Так же много экспериментов проводилось с _Detectron2_. Сначала я ставил проект и обрабатывал отдельные изображения тремя предобученными сетями, две реализуют instance segmentation - поиск, классификация и выделение маски знакомых объектов, и panoptic segmentation - сеть пытается отнести кажый пиксель изображения к какому-либо знакомому классу. Третья сеть делает предикт ключевых точек на теле изображенного человека. -->

Also many experiments were carried out with _Detectron2_. First, I set up the project and processed individual images with three pre-trained networks, two implement instance segmentation - searching, classifying and extracting a mask of familiar objects, and panoptic segmentation - the network tries to attribute each image pixel to a familiar class. The third network makes a prediction of key points on the body of the depicted person.

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

<!-- Далее написал скрипт для работы Detectron2 в реалтайме. -->

Next, I wrote a script for Detectron2 to work in real time.

<p>
 <img src="/imgs/software/1.png" width="300"/>
 <img src="/imgs/software/2.png" width="300"/>
</p>

<p>
 <img src="/imgs/software/3.png" width="300"/>
 <img src="/imgs/software/4.png" width="300"/>
</p>

<!-- Записи не сохранилось, как и самой системы, только кадры. Система оказалась слишком прожорливая для нашего железа и выдавала максимум 2-3 fps. -->

The records were not preserved, as well as the system itself, only frames. The system turned out to be too gluttonous for our hardware and gave out a maximum of 2-3 fps.

<!-- Было решено отказаться от Detectron2 и искать более специализированные менее ресурсоёмкие технологии. -->

It was decided to abandon Detectron2 and look for more specialized less resource-intensive technologies.

<!-- Сейчас мы открываем для себя большое количество софта от Intel оптимизированного под их аппаратные платформы Intel NUC, Intel RealSense, Intel Movidius, наш робот, напоминаю, оснащён всеми этими устройствами. Заявленая эффективность такого решения впечатляет, сейчас разбираемся с их инфраструктурой.
 -->
<br>
<br>

### System for recognition of key points on the human body

<!-- Для распознавания ключевых точек вместо тяжелого Detectron2 я использовал технологию [Intel Skeleton Tracking](https://www.intelrealsense.com/skeleton-tracking/), оптимизированную под Intel NUC и Intel RealSense, которую можно ещё и ускорить, добавив дополнительные вычислительные ядра в Intel Neural Compute Stick 2. Как будет применена технология в нашем проекте и будет ли она применена вообще я ещё не знаю, но не опробовать её, имея на руках 3D-камеру и всё сопутствующее аппаратное обеспечение, я не могу. -->

To recognize key points, instead of the heavy Detectron2, I used [Intel Skeleton Tracking](https://www.intelrealsense.com/skeleton-tracking/) technology, optimized for Intel NUC and Intel RealSense, which can also be accelerated by adding additional computing cores on an Intel Neural Compute Stick 2.

<!-- _Демо работы системы распознавания ключевых точек Intel NUC 115 + RealSense D455:_ -->

_Demo of the Intel NUC 115 + RealSense D455 keypoint recognition system:_

<img src="/imgs/video/key.gif" width="700"/>

<!-- Как можно заметить система работает хорошо и бодро, 13-16 fps стабильно.  -->

As you can see, the system works well and cheerfully, 13-16 fps is stable.

<br>
<br>

### Face recognition system

<!-- Так же было решено опробовать различные технологии распознавания лиц чтобы робот, как минимум, мог направлять голову в сторону лица человека. -->

It was also decided to try out various face recognition technologies so that the robot could at least point its head in the direction of a person's face.

<!-- _Скрипт для распознавания лиц с 68 ключевыми точками:_ -->

_Script for face recognition with 68 key points:_

 <img src="/imgs/software/my_face.gif" width="700"/>

<img src="/imgs/photos/face_222.png" width="500"/>

*Репозиторий в работе...*
