

<p align = center>
<img src=readme/imgs/DeepSeek-Logo.png ,width=200, height=150>
  <br>
<img src=readme/imgs/ChatGPT-Logo.png ,width=250, height=140>
<img src=readme/imgs/Qwen-Logo.png ,width=135, height=140> 
</p>
<br>

[![Telegram Channel](https://img.shields.io/badge/Telegram-Channel-blue?style=for-the-badge&logo=telegram)](https://t.me/ArcaneDevStudio)
[![Contact Me](https://img.shields.io/badge/Contact-Me-green?style=for-the-badge&logo=telegram)](https://t.me/Nam4iks)


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
Как могли уже догадаться TF-IDF Data-Sciense метод отражающиий частоту использования слова в документе и его важнсти в контексте, с его помощью легко отличаются тексты написанные нейросетью от человеческих.  
```math
\text{TF-IDF}(t, d, D) = \left( \frac{f_{t, d}}{\sum_{t' \in d} f_{t', d}} \right) \times \log \left( \frac{N}{|\{d \in D : t \in d\}|} \right)
```
или же более простая формула 
<p align = center>
<img src=readme/imgs/TFIDF.jpg, width=500, height=150>
</p>
# Как отличить нейро-медиа от настоящего?
## Математический взгляд

# Как отличить нейро-код от человеческого?
## Математический взгляд
