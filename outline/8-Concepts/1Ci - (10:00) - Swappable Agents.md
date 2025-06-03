

## 🧠 What Are Swappable Agents?

Swappable agents are modular behavior units—each responsible for a task like displaying an image, logging data, or cleaning inputs. Instead of hardcoding every function, the system **calls agents dynamically based on names or modes**.

Think:
📦 `agent("ImageHandler")->run("file.bmp")`
🧽 `agent("DataCleaner")->filter("/images")`

---

## 🔁 Why It’s Great for Your Labs

1. 🔧 **Custom Capstone Flexibility** – Students can register new agents (e.g., “ImageClassifier”) without touching the FSM.
2. 🧱 **Reusability** – Agents are portable. Write once, reuse across projects.
3. 🧪 **Live Experimentation** – Try different pipelines (`useSpiffs()` vs `useHeaders()`) by swapping the active agent.

---

## 🧩 Basic Implementation Plan (Future)

We’ll use a registry like this:

```cpp
typedef void (*AgentFunc)(String param);

struct Agent {
  String name;
  AgentFunc run;
};

Agent agentRegistry[] = {
  {"ImageHandler", displayImageAgent},
  {"DataCleaner", cleanInputAgent},
  {"Logger", logAgent}
};

Agent* getAgent(String name) {
  for (int i = 0; i < sizeof(agentRegistry)/sizeof(agentRegistry[0]); i++) {
    if (agentRegistry[i].name == name) return &agentRegistry[i];
  }
  return nullptr;
}
```

---

## 📦 Example Usage in Your FSM:

Replace:

```cpp
process_image("some_image.h");
```

With:

```cpp
Agent* imgAgent = getAgent("ImageHandler");
if (imgAgent) imgAgent->run("some_image.h");
```

---

## ✅ Summary

| Feature        | Benefit                          |
| -------------- | -------------------------------- |
| Agent Registry | Plug-and-play logic components   |
| Student Proof  | Easy to extend, hard to break    |
| FSM-Aware      | Works directly inside state loop |
| Capstone-Ready | Enables branching behaviors      |

---

### Let's start by building our first agent then in future labs  we can call on it.
