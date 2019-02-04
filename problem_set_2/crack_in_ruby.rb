ALPHA = ("a".."z").to_a.insert(0, " ") # Adding 0 as the first value to make sure algo iterates over a values in subsequent iterations
password = ARGV[0]
string = ""
password.length.times { string << " " }
head = 0
start_time = Time.now

def success(count, word, time_taken)
  puts "Found! It took #{count} tries and #{time_taken} seconds and the word is #{word}"
end

def next_letter_in_alphabet(letter)
  next_index = ALPHA.index(letter) + 1
  ALPHA[next_index]
end

count = 0
found  = false
length = password.length - 1

until found
  count += 1
  if string == password
    time_taken = Time.now - start_time
    found = true
    success(count, string, time_taken)
  end
  next_letter = next_letter_in_alphabet(string[head])
  if next_letter
    string[head] = next_letter
    head -= 1 if head > 0
  else # End of alphabet, increase the head for iteration by 1
    string[head] = ' '
    head += 1
    break if head > length
  end
end

puts "Didn't find it" unless found
