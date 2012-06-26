from random import choice

def encrypt(plaintext, subkey, transkey):
    LETTERS = "ABCDEFGHIKLMNOPQRSTUVWXYZ0123456789 "
    CODE = "ADFGVX"
    plaintext = plaintext.upper()
    plaintext = plaintext.replace('J', 'I')
    plaintext = ''.join(x for x in plaintext if x in LETTERS)
    cipher = dict(zip(subkey, (x + y for x in CODE for y in CODE)))
    first = ''.join([cipher[c] for c in plaintext])
    to_pad = len(transkey) - len(first) % len(transkey)
    if to_pad == len(transkey):
        to_pad = 0
    first += ''.join(choice(CODE) for _ in range(to_pad))
    assert len(first) % len(transkey) == 0
    step = len(transkey)
    parts = [(k, first[i::step]) for i, k in enumerate(transkey)]
    parts.sort(key=lambda x: x[0])
    return ''.join(x[1] for x in parts)

def decrypt(ciphertext, subkey, transkey):
    stkey = sorted(transkey)
    step = len(ciphertext) // len(transkey)
    parts = [(k, ciphertext[i*step:(i+1)*step]) for i, k in enumerate(stkey)]
    ordered_parts = []
    for k in transkey:
        for i, (key, value) in enumerate(parts):
            if key != k:
                continue
            ordered_parts.append(value)
            parts.pop(i)
            break
    tposed = [''.join(x) for x in zip(*ordered_parts)]
    first = ''.join(tposed)
    CODE = "ADFGVX"
    cipher = dict(zip((x + y for x in CODE for y in CODE), subkey))
    letter_poss = range(0, len(first), 2)
    letters = [cipher[first[i:i+2]] for i in letter_poss]
    return ''.join(letters)

