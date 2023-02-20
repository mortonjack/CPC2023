/* IDEAS:
 * Count the number of OPENING BRACKETS with a valid sequence before
 * Count the number of CLOSING BRACKETS with a valid sequence after
 * Count the TOTAL BRACKETS
 * -- This works, but it would fail in the case of ( () ) because it would subtract the sequence twice
 * We also know by looking inside the brackets that there is 1 opening/closing bracket inside (2 opening total 1 closing total)
 * From here how do we distinguish between ( )( )?
 * If we know the number of SELF CONTAINED sequences before and after as well
 * ( () )
 * 0 01 2 - self contained before
 * 2 10 0 - self contained after
 * 1 22 2 - valid opening
 * 2 22 1 - valid closing
 * ( )( )
 * 0 11 2 - self contained before
 * 2 11 0 - self contained after
 * 1 12 2 - valid opening
 * 2 21 1 - valid closing
 * Now both sequences contain the 1 valid opening before and 1 valid closing after
 * The former has... nah this won't work
 */

/* BINARY SEARCH
 * Let's say we can find the first opening/closing bracket with a valid ending within each sequence
 * If we have () ... () how can we distinguish between () ))(( () and () (()) ()
 */


/* input: ())(())(())(
 * valid: () (())(())
 * before 01111233344
 * after  54443222100
 * depth  10012101210
 *
 * input: ())(()())((()
 * valid: () (()())  ()
 * before 0111122344445
 * after  5444322111110
 * depth  1001212100010
 */
