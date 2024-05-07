WEBSITE="https://kaba.ai"
DESCRIPTION="Kaba Labs, Inc"
NAME="Flipper BioAmp EXG Pill Bio Signal Acquisition"

# Get the git commit
SHA=$(shell git rev-parse --short HEAD)
BUILD_COUNT=$(shell git rev-list --count HEAD)
BUILD_TAG="${BUILD_COUNT}.${SHA}"

build: banner 
	@ufbt
	@echo "Done!"

format:
	@ufbt format

banner:
	@echo ""
	@echo ""
	@echo "██╗░░██╗░█████╗░██████╗░░█████╗░"
	@echo "██║░██╔╝██╔══██╗██╔══██╗██╔══██╗"
	@echo "█████═╝░███████║██████╦╝███████║"
	@echo "██╔═██╗░██╔══██║██╔══██╗██╔══██║"
	@echo "██║░╚██╗██║░░██║██████╦╝██║░░██║"
	@echo "╚═╝░░╚═╝╚═╝░░╚═╝╚═════╝░╚═╝░░╚═╝"
	@echo ""
	@echo "        https://kaba.ai         "
	@echo ""
	@echo ""
	@echo "Project: $(NAME) $(VERSION)"
	@echo "Description: $(DESCRIPTION)"
	@echo "Website: $(WEBSITE)"
	@echo "BUILD TAG: $(BUILD_TAG)"
	@echo ""
	@echo ""

pack:
	@npm install
	@npm run build

start: banner
	@npm run start

clean: banner
	# @rm -rf ./node_modules/
	# @rm -rf ./package-lock.json
	@rm -rf dist/
	# @rm -rf cache/

.PHONY: push
