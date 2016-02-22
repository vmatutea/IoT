from twython import TwythonStreamer
execfile("initkeys.py")
n=0
def increase():
	global n
	n +=1
	print n
	if n>2:
		print "Ian G. Harris is popular"
class MyStreamer(TwythonStreamer):
	def on_success (self,data):
		if 'text' in data:
			print "Ian in Twitt"
			increase()



stream=MyStreamer(c_k,c_s,a_t,a_s)
stream.statuses.filter(track="Ian G. Harris")
