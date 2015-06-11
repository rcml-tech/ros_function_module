# ros_function_module
Module for ROS


Данный модуль позволяет отправлять в указанные топики указанные сообщения стандартных типов поддерживаемых ROS.
*Тестировалось на ROS Indigo Igloo*

####используемые типы:

std_msgs::Header
std_msgs::MultiArrayDimension
std_msgs::Bool
std_msgs::Byte
std_msgs::Char
std_msgs::ColorRGBA
std_msgs::Float64
std_msgs::Int64
std_msgs::String
std_msgs::Time
std_msgs::UInt64
geometry_msgs::Vector3
geometry_msgs::Accel
geometry_msgs::Point
geometry_msgs::Pose
geometry_msgs::Pose2D
geometry_msgs::Quaternion
geometry_msgs::Transform
geometry_msgs::Twist
geometry_msgs::Wrench


перед работой необходимо запустить функцию initNode().
Она запустит узел в ROS.
После завершения раоты необходимо выполнить функцию closeNode().
Она заверншит работу узла ROS.

### Список функций модуля
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
sendTransform(**topic**, **tx**, **ty**, **tz**, **rx**, **ry**, **rz**, **rw**) | Отправляет в топик **topic** сообщение типа Transform. **tx**, **ty**, **tz** - координаты положения центра новой системы координат в координатах текущей системы. **rx**, **ry**, **rz**, **rw** - Кватернион поворота новой системы координат относительно текущей.
sendTwist(**topic**, ) | Отправляет в топик **topic** сообщение типа Twist.       
sendWrench(**topic**, ) | Отправляет в топик **topic** сообщение типа Wrench.       
initNode() | Создает узел ситсемы ROS.
clearNode() | Завершает работу узла ROS.


#### Компиляция
Для компиляции и сборки в ROS используется скрипт [catkin_make](http://wiki.ros.org/catkin/commands/catkin_make)  . По сути это скрипт запускающий cmake и использующий переменные окружения ROS.
Структура файлов модуля в репозитории организована таким образом чтобы было удобно использовать этот скрипт.
Для сборки достаточно поместить модуль в окружение [Catkin Workspace](http://wiki.ros.org/catkin/workspaces) и запустить **catkin_make** в корневом каталоге окружения **Catkin Workspace**.














