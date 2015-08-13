# Модуль сообщений ROS для языка RCML

Данный модуль позволяет отправлять в указанные топики сообщения стандартных типов поддерживаемых ROS.

####используемые типы:
Типы |
 ------- |
std_msgs::Header |
std_msgs::MultiArrayDimension |
std_msgs::Bool |
std_msgs::Byte |
std_msgs::Char |
std_msgs::ColorRGBA |
std_msgs::Float64 |
std_msgs::Int64 |
std_msgs::String |
std_msgs::Time |
std_msgs::UInt64 |
geometry_msgs::Vector3 |
geometry_msgs::Accel |
geometry_msgs::Point |
geometry_msgs::Pose |
geometry_msgs::Pose2D |
geometry_msgs::Quaternion |
geometry_msgs::Transform |
geometry_msgs::Twist |
geometry_msgs::Wrench |


### Список функций модуля
Определение  | Описание
--------|---------
sendHeader(**topic**, **frame_id**, **seq**, **sec**, **nsec**) | Отправляет в топик **topic** сообщение типа Header. **frame_id** - Идентификатор системы координат, строкового типа. **seq** - ID системы координат. **sec** и **nsec** - секунды и наносекунды временной метки.        
sendMultiArrayDimension(**topic**, **label**, **size**, **stride**) | Отправляет в топик **topic** сообщение типа MultiArrayDimension. **label** - метка данного измерения, **size** - размер измерения, **stride** - шаг измерения.
sendBool(**topic**,**data**) | Отправляет в топик **topic** данные **data** типа Bool.
sendByte(**topic**, **data**) | Отправляет в топик **topic** данные **data** типа Byte.     
sendChar(**topic**, **data**) | Отправляет в топик **topic** данные **data** типа Char.     
sendColorRGBA(**topic**, **r**, **g**, **b**, **a** ) | Отправляет в топик **topic** сообщение типа ColorRGBA.  **r**,**g**, **b** - значения красного, зеленого и голубого цветов соответственно. **a** - задает прозрачность цвета.
sendFloat64(**topic**, **data** ) | Отправляет в топик **topic** данные **data** типа Float64.       
sendInt64(**topic**, **data** ) | Отправляет в топик **topic** данные **data** типа Int64.       
sendString(**topic**, **data** ) | Отправляет в топик **topic** данные **data** типа String.       
sendTime(**topic**, **sec**, **nsec** ) | Отправляет в топик **topic** сообщение типа Time. **sec** и **nsec** - секунды и наносекунды.       
sendUInt64(**topic**, **data** ) | Отправляет в топик **topic** данные **data** типа UInt64.       
sendVector3(**topic**, **x**, **y**, **z**) | Отправляет в топик **topic** сообщение типа Vector3.  **x**, **y**, **z** - соответствующие координаты.       
sendAccel(**topic**, **lx**, **ly**, **lz**, **ax**, **ay**, **az**) | Отправляет в топик **topic** сообщение типа Accel. **lx**, **ly**, **lz** - линейное ускорение по соответствующим координатам. **ax**, **ay**, **az**  - угловое ускорение по соответствующим координатам.     
sendPoint(**topic**, **x**, **y**, **z**) | Отправляет в топик **topic** сообщение типа Point. **x**, **y**, **z** -оответствующие координаты точки.    
sendPose(**topic**, **px**, **py**, **pz**, **ox**, **oy**, **oz**, **ow** ) | Отправляет в топик **topic** сообщение типа Pose. **px**, **py**, **pz**  - соответствующие координаты положения. **ox**, **oy**, **oz**, **ow** - ориентация в пространстве в форме Кватерниона.
sendPose2D(**topic**, **x**, **y**, **theta**) | Отправляет в топик **topic** сообщение типа Pose2D. **x**, **y** - координаты положения, **theta** - угол поворота.   
sendQuaternion(**topic**, **x**, **y**, **z**, **w**) | Отправляет в топик **topic** сообщение типа Quaternion. **x**, **y**, **z**, **w** - ориентация в пространстве.       
sendTransform(**topic**, **tx**, **ty**, **tz**, **rx**, **ry**, **rz**, **rw**) | Отправляет в топик **topic** сообщение типа Transform. Переход из одной системы координат в другую. **tx**, **ty**, **tz** - координаты положения центра новой системы координат в координатах текущей системы. **rx**, **ry**, **rz**, **rw** - Кватернион поворота новой системы координат относительно текущей.
sendTwist(**topic**, **lx**, **ly**, **lz**, **ax**, **ay**, **az** ) | Отправляет в топик **topic** сообщение типа Twist. Представление скорости в пространстве. **lx**, **ly**, **lz** - вектор линейной скорости. **ax**, **ay**, **az** - вектор угловой скорости.
sendWrench(**topic**, **fx**, **fy**, **fz**, **tx**, **ty**, **tz**) | Отправляет в топик **topic** сообщение типа Wrench. Представление силы в пространстве.  **fx**, **fy**, **fz** - линейная часть силы. **tx**, **ty**, **tz** - угловая часть силы.
initNode() | Создает узел ситсемы ROS.
clearNode() | Завершает работу узла ROS.


 - При первом обращении к любой из функций модуля будет создан узел ROS. Он будет существовать пока не завершится программа на RCML либо не будет вызвана функция closeNode().
 - Чтобы повторно создать узел ROS необходимо вызвать функцию initNode().


#### Компиляция
 - Для компиляции и сборки в ROS используется скрипт [catkin_make](http://wiki.ros.org/catkin/commands/catkin_make).<br>
 Структура файлов модуля в репозитории организована таким образом чтобы было удобно использовать этот скрипт.
 - Для сборки достаточно поместить модуль в окружение [Catkin Workspace](http://wiki.ros.org/catkin/workspaces) и запустить **catkin_make** в корневом каталоге окружения **Catkin Workspace**.

Удобная структура каталогов для использования catkin_make:

```
workspace_folder/         -- WORKSPACE
  src/                    -- SOURCE SPACE
    ros_function_module/  -- Каталог исходных файлов модуля для RCML
      sendCommandsLib.cpp
      rosHeaders.h
      ...
      src
      	...
```

- [Руководство по установке ROS на Ubuntu](http://wiki.ros.org/indigo/Installation/Ubuntu)
- [Информация о настройке окружения ROS](http://wiki.ros.org/ROS/Tutorials/InstallingandConfiguringROSEnvironment)











