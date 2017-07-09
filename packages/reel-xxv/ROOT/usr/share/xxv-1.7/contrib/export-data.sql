--
-- Store Table from Database xxv to files
--

select * INTO OUTFILE '/tmp/autotimer.sav' from AUTOTIMER;
select * INTO OUTFILE '/tmp/chronicle.sav' from CHRONICLE;
select * INTO OUTFILE '/tmp/medialib_actors.sav' from MEDIALIB_ACTORS;
select * INTO OUTFILE '/tmp/medialib_videodata.sav' from MEDIALIB_VIDEODATA;
select * INTO OUTFILE '/tmp/medialib_videogenre.sav' from MEDIALIB_VIDEOGENRE;
select * INTO OUTFILE '/tmp/movetimer.sav' from MOVETIMER;
select * INTO OUTFILE '/tmp/user.sav' from USER;

