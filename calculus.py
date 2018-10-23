# Estimating areas using the midpoint formula
print("Let's estimate the area under the graph of y=9cos(x^2) for a given interval.")

import math
dictionary = {"left-hand":"under-", "right-hand":"over-", "midpoint":"either an under- or over-"}
method = input("Would you like to use the left-hand, right-hand or midpoint method?").lower()
if method == "midpoint" or method == "mid":
  print("Ok, this will give us " + dictionary["midpoint"] + "estimate, but it is usually more accurate. Good choice.")
  n = int(input("What n value would you like to use (greater than 1)?"))
  integrand_a = int(input("What is the lower limit of integration?"))
  integrand_b = int(input("What is the upper limit of integration?"))
  cos_numbers = []
  
  integrate_range = (integrand_b) - (integrand_a)
  x = float(integrate_range)/n
  numbers = [integrand_a+x/2]
  interval = numbers[0]
  
  for i in range(int(n-1)):
    interval+=x
    numbers.append(interval)
  
  for fx in numbers:
    cos = 9*(math.cos(fx**2)) # function: y = 9cos(x^2)
    cos_numbers.append(cos)
  #print(x)
  #print(numbers)
  #print(cos_numbers)
  print("The estimated area is " + str(math.fsum(cos_numbers)*x))

elif method == "left-hand" or method == "left" or method == "lefthand":
  print("Ok, this will give us an " + dictionary["left-hand"] + "estimate.")
  n = int(input("What n value would you like to use (greater than 1)?"))
  integrand_a = int(input("What is the lower limit of integration?"))
  integrand_b = int(input("What is the upper limit of integration?"))
  cos_numbers = []
  
  integrate_range = (integrand_b) - (integrand_a)
  x = float(integrate_range)/n
  numbers = [integrand_a]
  interval = numbers[0]
  
  for i in range(int(n-2)):
    interval+=x
    numbers.append(interval)
  
  for fx in numbers:
    cos = 9*(math.cos(fx**2)) # function: y = 9cos(x^2)
    cos_numbers.append(cos)
  #print(x)
  #print(numbers)
  #print(cos_numbers)
  print("The estimated area is " + str(math.fsum(cos_numbers)*x))

elif method == "right-hand" or method == "right" or method == "righthand":
  print("Ok, this will give us an " + dictionary["right-hand"] + "estimate.")
  n = int(input("What n value would you like to use (greater than 1)?"))
  integrand_a = int(input("What is the lower limit of integration?"))
  integrand_b = int(input("What is the upper limit of integration?"))
  cos_numbers = []
  
  integrate_range = (integrand_b) - (integrand_a)
  x = float(integrate_range)/n
  numbers = [integrand_a]
  interval = numbers[0]
  
  for i in range(int(n-1)):
    interval+=x
    numbers.append(interval)
  
  for fx in numbers:
    cos = 9*(math.cos(fx**2)) # function: y = 9cos(x^2)
    cos_numbers.append(cos)
  #print(x)
  #print(numbers)
  #print(cos_numbers)
  print("The estimated area is " + str(math.fsum(cos_numbers)*x))
