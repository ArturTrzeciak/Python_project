import requests
from django.shortcuts import render

def index(request):
    appid = 'bc084494caa58d430710c47c1d6397a0'
    url = 'https://api.openweathermap.org/data/2.5/weather?q={}&units=metric&appid=' + appid

    city = 'London'
    res = requests.get(url.format(city)).json()

    city_info = {
        'city': city,
        'temp': res["main"]["temp"],
        'icon': res["weather"][0]["icon"]
    }

    conplex = {'info': city_info}

    return render(request, 'Wether/index.html', conplex)