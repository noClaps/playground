using Printf

function points(up, down)
	return up - down
end

function percentage(up, down)
	if up === 0
		return 0
	end

	return round(Int, up / (up+down) * 100)
end

for up = 0:6000
	for down = 0:6000
		if points(up, down) === 4 && percentage(up, down) === 84
			@printf "Upvotes: %d, downvotes: %d\n" up down
		end
	end
end
