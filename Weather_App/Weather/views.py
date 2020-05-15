import requests
from django.shortcuts import render
from .models import City
from .forms import CityForm

def index(request):
    appid = 'bc084494caa58d430710c47c1d6397a0'
    url = 'https://api.openweathermap.org/data/2.5/weather?q={}&units=metric&appid=' + appid

    if(request.method == 'POST'):
        form = CityForm(request.POST)
        form.save()

    form = CityForm()

    cities = City.objects.all()

    all_cities = []

    for city in cities:
        res = requests.get(url.format(city.name)).json()
        сity_info = {
           'city': city.name,
           'temp': res["main"]["temp"],
           'icon': res["weather"][0]["icon"]
        }

        all_cities.append(сity_info)

    conplex = {'all_info': all_cities, 'form': form}

    return render(request, 'Wether/index.html', conplex)
