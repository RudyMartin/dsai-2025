# Repo RAG

Building a RAG engine for a specific knowledge base is a core use case for Dspy and a great LLM python exercise.

Here's a Colab-ready Dspy application that allows you to chat with the content of the RudyMartin/dsai-2025 GitHub repository.

Key components:

Repository Cloning & Data Extraction: Fetches the .md and .ipynb (Jupyter Notebook) files from the repo.
Text Processing: Uses LangChain's RecursiveCharacterTextSplitter to break down documents into smaller, manageable chunks.
Embedding & Vector Store: Utilizes SentenceTransformerEmbeddings to convert text chunks into numerical vectors and stores them in an in-memory ChromaDB instance.
Dspy Integration:
- Defines a custom Dspy Retrieve module to query the ChromaDB vector store.
- Creates a Dspy Chain to orchestrate retrieval and generation.
- Sets up the Dspy language model (gpt-3.5-turbo via OpenAI, but configurable).
- Interactive Chat: Provides a simple loop for you to ask questions and receive answers based on the repository's content.

**How to Use in Google Colab:**
Open a new Google Colab notebook.
Copy and paste the entire code block into a cell.
Run the cell (Shift+Enter).
The script will:
Install necessary libraries.
Clone the GitHub repository.
Process all markdown (.md) and Jupyter notebook (.ipynb) files, chunk them, and create a vector store. This might take a few minutes depending on the repo size and Colab's resources.
Prompt you to enter your OpenAI API key. Paste your key and press Enter.
Initialize the Dspy RAG engine.
Start an interactive chat loop.
Example Questions you can ask:
"What are the main topics covered in this course?"
"Are there any materials on Deep Learning?"
"Summarize the content about machine learning models."
"Where can I find information about natural language processing?"
"What is described in lectures/slides/lec_01_intro.md?" (You might need to refine this to be more topic-based if the content inside the file is less detailed than the overall course overview).
"Explain the purpose of the projects directory."


**Why Mounting Google Drive is Recommended:**

Mounting Google Drive (/content/drive/My Drive) connects your Colab VM to your persistent cloud storage. When you clone the repository into a folder within My Drive, the files are actually being saved to your Google Drive account, not just the temporary VM.

Persistence: The dsai-2025 folder will remain in your Google Drive even after your Colab session ends.
Accessibility: You can access these files from other Colab notebooks, other computers, or directly from your Google Drive interface.
No Re-cloning: When you start a new Colab session, you just need to mount Google Drive again, and the repository will already be there, saving you the time of re-cloning. You might still want to git pull inside the cloned directory if you need to ensure you have the absolute latest version from the original GitHub repo.
