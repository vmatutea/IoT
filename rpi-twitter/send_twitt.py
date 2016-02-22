from twython import Twython
execfile("initkeys.py")
api=Twython(c_k,c_s,a_t,a_s)
api.update_status(status="Rpi is good")
