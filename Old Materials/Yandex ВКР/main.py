# Переменные состояния
STATE_REQUEST_KEY = 'session'
STATE_RESPONSE_KEY = 'session_state'

# Реализация функций вывода
def make_response(text, tts=None, card=None, state=None):
    response = {
        'text': text,
        'tts': tts if tts is not None else text,
    }
    if card is not None:
        response['card']=card
    webhook_response = {
        'response': response,
        'version': '1.0',
    }
    if state is not None:
        webhook_response[STATE_RESPONSE_KEY]=state
    return webhook_response

# Вывод изображения
def img_gallery(image_ids):
    items=[{'image_id':image_id} for image_id in image_ids]
    return{
        'type':'ImageGallery',
        'items':items,
    }

# Привественное сообщение
def welcome_massage(event):
    text = ('Вас приветствует голосовой помощник студента МТУСИ. Если вы студент, пройдите авторизацию используя команду ВХОД и свой идентификатор.' 
    'Если вы просто сторонний слушатель, интересующийся институтом, можете смело задавать интересующие вас вопросы о вузе и его истории.')
    return make_response(text)

# Функция при отсутвии понимания высказывания
def fallback(event):
    return make_response('Запрос некорректен. Прошу повторить.')

# Функция при отсутвии понимания высказывания студент 1
def fallback_1(event):
    return make_response('Запрос некорректен. Прошу повторить.', state={
        'screen':'Student_1'
    })

    # Функция при отсутвии понимания высказывания студент 2
def fallback_2(event):
    return make_response('Запрос некорректен. Прошу повторить.', state={
        'screen':'Student_2'
    })

# О МТУСИ
def about_MTUSI(event):
    text = 'МТУСИ лучший вуз!'
    return make_response(text)

def MTUCI_img(event):
    return make_response(text='',
        tts='',
        card=img_gallery(image_ids=['997614/cba229278c6933e4ff43',])
    )



# Вход в аккуант первого сутдента
def Vhod_User_ID_1(event):
    text = 'Спасибо за авторизацию. Добрый день, Дубельщиков Александр, учащийся группы БУТ1701.'
    return make_response(text, state={
        'screen':'Student_1'
    })

# Вход в аккаунт второго студента
def Vhod_User_ID_2(event):
    text = 'Спасибо за авторизацию. Добрый день, Рыжов Олег, учащийся группы БУТ1701_2.'
    return make_response(text, state= {
        'screen':'Student_2'
    })

def dolg_1(event, intent_name='dolg_1'):
    text = 'У вас есть задолженности по предмету Case средства'
    return make_response(text, state= {
        'screen':'Student_1'
    })

def dolg_2(event, intent_name='dolg_2'):
    text = 'Поздравляю, у вас нет задолженностей!'
    return make_response(text, state= {
        'screen':'Student_2'
    })

def o_tutovoi(event):
    text = 'Доцент кафедры Интеллектуальные системы в управлении и автоматизации факультета "Информационные технологии" МТУСИ. Кандидат технических наук. Имеет более 40 научных работ. Информация взята с официального сайта ИСУиА.'
    return make_response(text)

# Кто ведет уроки группа студента #1
def who_do_lesson(event):
    intent = event['request']['nlu']['intents']['who_do_lesson']
    lesson = intent['slots']['lesson']['value']
    if lesson == 'phs':
        return make_response(text='Файзулаев Владимир Нуруллаевич', state= {
        'screen':'Student_1'})
    elif lesson == 'bd':
        return make_response(text='Воронов Вячеслав Игоревич', state= {
        'screen':'Student_1'})
    elif lesson == 'obg':
        return make_response(text='Ерофеева Виктория Вячеславона', state= {
        'screen':'Student_1'})
    else:
        return fallback_1(event)

# Кто ведет уроки группа студента #2
def who_do_lesson_1(event):
    intent = event['request']['nlu']['intents']['who_do_lesson_1']
    lesson = intent['slots']['lesson']['value']
    if lesson == 'phs':
        return make_response(text='Файзулаев Владимир Нуруллаевич', state= {
        'screen':'Student_2'}, card=img_gallery(image_ids=['1540737/0a639a6ae357a6e60df8',]))
    elif lesson == 'bd':
        return make_response(text='Воронов Вячеслав Игоревич', state= {
        'screen':'Student_2'})
    elif lesson == 'obg':
        return make_response(text='Ерофеева Виктория Вячеславона', state= {
        'screen':'Student_2'})
    else:
        return fallback_2(event)

# Основная функция
def handler(event, context):
    intents = event ['request'].get('nlu', {}).get('intents')
    state=event.get('state').get(STATE_REQUEST_KEY, {})
    if event ['session']['new']:
        return welcome_massage(event)
    elif 'about_MTUSI' in intents:
        return about_MTUSI(event)
    elif 'o_tutovoi' in intents:
        return o_tutovoi(event)
    elif 'MTUCI_img' in intents:
        return MTUCI_img(event)
    elif 'Vhod_User_ID_1' in intents:
        return Vhod_User_ID_1(event)
    elif 'Vhod_User_ID_2' in intents:
        return Vhod_User_ID_2(event)
    elif state.get('screen') == 'Student_1':
            if 'dolg_1' in intents:
                return dolg_1(event, intent_name='dolg_1')
            elif 'who_do_lesson' in intents:
                return who_do_lesson(event)
            else:
                return fallback_1(event)

    elif state.get('screen') == 'Student_2':
            if 'dolg_2' in intents:
                return dolg_1(event, intent_name='dolg_2')
            elif 'who_do_lesson_1' in intents:
                return who_do_lesson_1(event)
            else:
                return fallback_2(event)
    else:
        return fallback(event)
