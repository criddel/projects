# Carmen Riddel
# March 30, 2018
# Break up Music Suggestor Bot

song_list = []
file = open("spotify.csv")
file.readline()

for line in file:
  	datalist = line.split(",")
  	artist = datalist[-1]
	song = datalist[-2]
  	valence = datalist[-4]
  	record = (artist, song, valence)
  	song_list.append(record)

for i in range(len(song_list)):
  	smallest = song_list[i]
  	smallest_index = i
  	for j in range(i+1, len(song_list)):
    		if song_list[j][2] < smallest[2]:
      			smallest = song_list[j]
      			smallest_index = j
      			song_list[smallest_index], song_list[i] = song_list[i], song_list[smallest_index]

feeling = input("Sorry to hear about your break-up. Would you like some positive jams to get you feelin' good, or would you like to wallow a bit? (positive, wallow, in between)").lower()
if feeling == "positive":
  	print("Here's a good playlist for you. \n")
  	for i in range(10):
    		print(song_list[-i-1][1] + " by " + song_list[-i-1][0])

elif feeling == "wallow":
	print("Here's a good playlist for you. \n")
  	for i in range(10):
    		print(song_list[i][1] + " by " + song_list[i][0])

elif feeling == "in between":
 	print("Here's a good playlist for you. \n")  
  	for i in range(len(song_list)):
    		if 0.76 < float(song_list[i][2]) < 0.77:
      			print(song_list[i][1] + " by " + song_list[i][0])
