from ctypes import * 

dll = CDLL("TF-LIB-v1.2.dll")
dll.hello()
result = dll.hash_function("result")

print(f"Hash of 'result' word = {result}" )
