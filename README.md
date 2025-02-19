
<a id="start"> </a>
<p align = center>
<img src=readme/imgs/DeepSeek-Logo.png ,width=200, height=150>
  <br>
<img src=readme/imgs/ChatGPT-Logo.png ,width=250, height=140>
<img src=readme/imgs/Qwen-Logo.png ,width=135, height=140> 
</p>
<br>

[![Telegram Channel](https://img.shields.io/badge/Telegram-Channel-blue?style=for-the-badge&logo=telegram)](https://t.me/ArcaneDevStudio)
[![Contact Me](https://img.shields.io/badge/Contact-Me-green?style=for-the-badge&logo=telegram)](https://t.me/Nam4iks)


Тем кому не нужно читать о методах Data Sciense анализа на нейросети, а Архитектура, Установка и тп ищите ниже в таблице 

| Языки     | Проект и другое |  Способы анализа |
|-----------|-----------------|------------------|
| [Русский](https//github.com/Nam4ik/Neuro-Content/blob/main/README.md)   | [Архитектура и сведения ](#proj)       | [TF-IDF](#TFIDF)       |
| [Английский](https://github.com/Nam4ik/Neuro-Content/blob/main/readme/READMEEN.md)  | [Установка](#install)        | _not created yet_        |
| _empty_ |[Быстрый старт](https://github.com/Nam4ik/Neuro-Content/blob/main/readme/QUICKSTART.md)|                    _not created yet_        | 
| _empty_ | [Инструменты реализации](#instr) |  _not created yet_|
| _empty_ |  [Web](deploy) | _not created yet_|

<br>

>[!WARNING]
>The app not released and can work unstable!
>Please report to me if you see an error


# Neuro-Content
Инструмент математически анализирующий код, тексты, изображения и видео контент и проверяет их на на генерацию нейросетями. 

>[!NOTE]
>Да простят меня школьники и студенты, аминь
>Вообще я не первый, по этому пожалуйста не кидайте все камни в меня 

# База

**Для начала стоит понимать что нейросети не создают новый контент, а перерабатывают тот на ктором они учились.** То есть у нейросети есть определенный датасет с помощью которого она училась => если данных о которых спрашивает пользователь не было в
датасете то она начинает придумывать на ходу, ну конечно если нейронка без функции веб поиска. ([Qwen](https://qwenlm.ai), [DeepSeek](https://chat.deepseek.com), [BlackBox](https://blackbox.ai) и другие)  
<p align = center>
<img src=readme/imgs/WebSearch1.jpg>
<img src=readme/imgs/WebSearch2.jpg>
<img src=readme/imgs/WebSearch3.jpg>
</p>
<br>


# Глубокое мышление - DeepSeek R1 и ChatGPT o3 

# Как происходит обучение нейросети и почему это так дорого

# Data sciense и то как отличить нейро-текст от человеческого
Как уже можно было догадаться отличается нейро текст от настоящего как правило большим кол-вом шаблонных конструкций, повторением некоторых слов и тп. Человеческий же текст может быть с опечатками, отсутствующими знаками препинания и многим чем другим, в подробности вдаваться не буду. 
## Как происходит проверка
1. Проверка по **TF-IDF**
2. Проверка по **БД** шаблонных фраз и ии текстов
3. Анализ на **речевые ошибки, пропущенные знаки препинания и опечатки**.

## TF-IDF 
<a id="TFIDF"></a>
Как могли уже догадаться TF-IDF Data-Sciense метод отражающиий частоту использования слова в документе и его важнсти в контексте, с его помощью легко отличаются тексты написанные нейросетью от человеческих.  
**TF-IDF (Term Frequency-Inverse Document Frequency) — это статистическая мера, используемая для оценки важности слова в документе или коллекции документов. Она учитывает частоту появления слова в документе (TF) и редкость этого слова в коллекции документов (IDF). Высокое значение TF-IDF указывает на то, что слово является значимым для данного документа.**
```math
\text{TF-IDF}(t, d, D) = \left( \frac{f_{t, d}}{\sum_{t' \in d} f_{t', d}} \right) \times \log \left( \frac{N}{|\{d \in D : t \in d\}|} \right)
```
<br>
или же более простая формула
<br>

```math
\text{TF-IDF} = \frac{\text{term frequency}}{\text{total words}} \times \log\left(\frac{\text{corpus size}}{1 + \text{documents with term}}\right)
```
<br>
и перевод ее на русский
<br>

```math
\text{TF-IDF} = \frac{\text{частота термина}}{\text{общее количество слов}} \times \log\left(\frac{\text{размер корпуса}}{1 + \text{документы с термином}}\right)
```
<br>

Значение TF-IDF показывает, насколько слово важно для данного документа относительно всего корпуса текстов. Высокое значение TF-IDF указывает на то, что слово часто встречается в данном документе и редко встречается в других документах, что делает его уникальным и важным для понимания содержания документа.
Для примера подсчитаем TF-IDF двух итоговых сочинений, нейро-сети и человека.

### Тема
Я выбрал одну тему, после чего написал один текст сам, а второй поручил написать giga.chat. 
**Тема Духовно-нравственные ориентиры в жизни человека - 304. Что значит достойно пережить поражение? (декабрь 2016).**

Тема итогового из итогового сочинения , объем - 120-150 слов. Промпт включал в себя тему, [полную формулировку задания итогового](https://sochinenie11.ru/o/348-kak-vyglyadit-zadanie.html) сочинения и укороченый объем. 

### **Нейро-сетевой [GigaChat](giga.chat)** 
>[!NOTE]
>Достойно пережить поражение – это умение сохранять самообладание и достоинство даже после неудачи, извлекая уроки для будущего успеха. Примером может служить произведение Льва Толстого "Война и мир". В романе князь Андрей Болконский терпит множество поражений: от ранений до потери любимой женщины. Однако он не опускает руки, а продолжает жить, стремясь к самосовершенствованию. Его духовная сила помогает ему преодолеть трудности и найти смысл в жизни. Таким образом, Толстой показывает, что истинная победа заключается не в отсутствии неудач, а в ?способности их принять и двигаться дальше.

### Человеческий

>[!NOTE]
>Заслуженно преодолевать неудачи - это умение сохранять спокойствие и достоинство даже после неудач и извлекать уроки для достижения будущего успеха. Хорошим примером может послужить произведение Льва Толстого “Война и мир". Князь Андрей Болконский в романе сталкивается с множеством трудностей: ранениями и потерей любимой женщины. Однако он не сдаётся и продолжает двигаться вперёд в стремлении к самосовершенствованию. Его духовная сила помогает ему преодолеть трудности и находить смысл жизни. Таким образом Лев Толстой показывает нам: настоящая победа заключается не в избежании неудач, а в умении принять их и двигаться дальше.

### Результат 

Результаты расчета TF-IDF (топ-10 значимых слов для каждого документа):
|Документ 1	|TF-IDF |	Документ 2 |	TF-IDF |
|-----------|-------|------------|---------|
|болконский|	0.0447|	болконский	|0.0447|
|толстого|	0.0358|	толстой	|0.0358|
|преодолевать	|0.0268|	поражение|	0.0268|
|заслуженно	|0.0179	|достойно|	0.0179|
избежании	|0.0179	|отсутствии|	0.0179|
|война	|0.0179	|пережить|	0.0179|
|духовная|	0.0179|	опускает|	0.0179|
|ранениями	|0.0179|	ранений	|0.0179|
|самосовершенствованию	|0.0179|	самосовершенствование	|0.0179|
|мир	|0.0179|	истинная	|0.0179|

# Как отличить нейро-медиа от настоящего?
## Математический взгляд

# Как отличить нейро-код от человеческого?
## Математический взгляд


# Проект, архитектуры и тп
<a id="proj"></a>

# Архитектура 
<a id="arch"></a>

# Установка
<a id="install"></a>

## Linux


## Windows 


## Web




# Инструментарий и языки  
<a id="instr"></a>

![Qt](https://img.shields.io/badge/Qt-%23217346.svg?style=for-the-badge&logo=Qt&logoColor=white)
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Python](https://img.shields.io/badge/python-3670A0?style=for-the-badge&logo=python&logoColor=ffdd54)
![Rust](https://img.shields.io/badge/rust-%23000000.svg?style=for-the-badge&logo=rust&logoColor=white)


# Зависимости 
<a id="req"></a>

# Деплой на web
<a id="deploy"></a>


## [**Назад**](#start)
