#from django.http import HttpResponse
from django.shortcuts import render


def hello(request):
    print(request)
    context = {'hello': '你好世界'}
    #context['hello'] = '你好世界'
    return render(request, 'hello.html', context)