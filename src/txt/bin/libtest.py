from ctypes import * 

dll = CDLL("LIBTDF.dll")
dll.hello()
result = dll.hash_function("result")

print(f"Hash of 'result' worf = {result}" )
