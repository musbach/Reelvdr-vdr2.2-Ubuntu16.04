USE vdr;
DELIMITER $$
CREATE PROCEDURE update_002()
BEGIN
IF NOT EXISTS
(
SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE table_name = 'timer_search' AND column_name = 'delMode'
)
THEN
ALTER TABLE timer_search ADD delMode TINYINT;
END IF;
IF NOT EXISTS
(
SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE table_name = 'timer_search' AND column_name = 'delAfterCountRecs'
)
THEN
ALTER TABLE timer_search ADD delAfterCountRecs SMALLINT;
END IF;
IF NOT EXISTS
(
SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE table_name = 'timer_search' AND column_name = 'delAfterDaysOfFirstRec'
)
THEN
ALTER TABLE timer_search ADD delAfterDaysOfFirstRec SMALLINT;
END IF;
IF NOT EXISTS
(
SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE table_name = 'timer_search' AND column_name = 'useAsSearchTimerFrom'
)
THEN
ALTER TABLE timer_search ADD useAsSearchTimerFrom INT;
END IF;
IF NOT EXISTS
(
SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE table_name = 'timer_search' AND column_name = 'useAsSearchTimerTil'
)
THEN
ALTER TABLE timer_search ADD useAsSearchTimerTil INT;
END IF;
IF NOT EXISTS
(
SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE table_name = 'timer_search' AND column_name = 'ignoreMissingEPGCats'
)
THEN
ALTER TABLE timer_search ADD ignoreMissingEPGCats TINYINT;
END IF;
IF NOT EXISTS
(
SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE table_name = 'timer_search' AND column_name = 'unmuteSoundOnSwitch'
)
THEN
ALTER TABLE timer_search ADD unmuteSoundOnSwitch TINYINT;
END IF;
END$$
DELIMITER ;
CALL update_002();
DROP PROCEDURE update_002;
