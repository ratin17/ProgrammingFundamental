space_invaders = [ ] 
player_pos = ( 200 , 25 ) 
level = 1 
max_level = 10


def play ( ) : 
    while ( level < max_level +1 ) :
         if len ( space_invaders ) == 0 : 
            level += 1 
            continue 

cs=['while','if','continue','len']

b=['ArithmeticError', 'AssertionError', 'AttributeError', 'BaseException', 
'BufferError', 'BytesWarning', 'DeprecationWarning', 'EOFError', 'Ellipsis',
 'EnvironmentError', 'Exception', 'False', 'FloatingPointError', 
'FutureWarning', 'GeneratorExit', 'IOError', 'ImportError', 'ImportWarning', 
'IndentationError', 'IndexError', 'KeyError', 'KeyboardInterrupt', 
'LookupError', 'MemoryError', 'NameError', 'None', 'NotImplemented', 
'NotImplementedError', 'OSError', 'OverflowError', 'PendingDeprecationWarning', 
'ReferenceError', 'RuntimeError', 'RuntimeWarning', 'StandardError', 
'StopIteration', 'SyntaxError', 'SyntaxWarning', 'SystemError', 'SystemExit', 
'TabError', 'True', 'TypeError', 'UnboundLocalError', 'UnicodeDecodeError', 
'UnicodeEncodeError', 'UnicodeError', 'UnicodeTranslateError', 'UnicodeWarning', 
'UserWarning', 'ValueError', 'Warning', 'WindowsError', 'ZeroDivisionError', 
'_', '__debug__', '__doc__', '__import__', '__name__', '__package__', 'abs', 
'all', 'any', 'apply', 'basestring', 'bin', 'bool', 'buffer', 'bytearray', 
'bytes', 'callable', 'chr', 'classmethod', 'cmp', 'coerce', 'compile', 
'complex', 'copyright', 'credits', 'delattr', 'dict', 'dir', 'divmod', 
'enumerate', 'eval', 'execfile', 'exit', 'file', 'filter', 'float', 'format', 
'frozenset', 'getattr', 'globals', 'hasattr', 'hash', 'help', 'hex', 'id', 
'input', 'int', 'intern', 'isinstance', 'issubclass', 'iter', 'len', 'license', 
'list', 'locals', 'long', 'map', 'max', 'memoryview', 'min', 'next', 'object', 
'oct', 'open', 'ord', 'pow', 'print', 'property', 'quit', 'range', 'raw_input', 
'reduce', 'reload', 'repr', 'reversed', 'round', 'set', 'setattr', 'slice', 
'sorted', 'staticmethod', 'str', 'sum', 'super', 'tuple', 'type', 'unichr', 
'unicode', 'vars', 'xrange', 'zip']


for c in cs:
    # print(c)
    if c in b:
        print(c)
