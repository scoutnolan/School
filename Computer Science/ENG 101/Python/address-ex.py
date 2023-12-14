def address_book(f_name, l_name, dob, email_addy, phone=''):
    """Return a dictionary of information about a friend"""
    person={'first': f_name, 'last': l_name, 'birthday':dob, 'Email':email_addy}
    if phone:
        person['cell'] = phone
    return person
friend = address_book('Rhonda', 'Gaede', 'June 12, 1960', 'gaeder@uah.edu', '256.521.5422')
print(friend)
