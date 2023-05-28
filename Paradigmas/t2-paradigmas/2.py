def lower_to_upper(s: str):
    return list(map(lambda x: x.capitalize(), s.split()))

print(lower_to_upper("lucy in the sky with diamonds"))