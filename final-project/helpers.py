import os
import json

from collections import OrderedDict
from random import choice


# Get data from json
def get_data(file):
    file = open(file, 'r')
    # https://docs.python.org/3/library/collections.html#collections.OrderedDict
    data = json.load(file, object_pairs_hook = OrderedDict)
    file.close()

    return data


# Get random status-code response class
def random_class(data):
    return choice(list(data))


# Get random status-code from response class
def random_code(classname, data):
    return choice(list(data[classname]['status']))