from twython import TwythonStreamer
execfile("initkeys.py")
class MyStreamer(TwythonStreamer):
	def on_success (self,data):
		if 'text' in data:
			print "Got it vic"
stream=MyStreamer(c_k,c_s,a_t,a_s)
stream.statuses.filter(track="vic iot")
