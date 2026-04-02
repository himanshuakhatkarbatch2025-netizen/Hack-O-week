class PrintJob:
    def __init__(self, job_id, document, pages):
        self.job_id = job_id
        self.document = document
        self.pages = pages


class PrinterQueue:
    def __init__(self):
        self.queue = []

    # Enqueue
    def add_job(self, job_id, document, pages):
        job = PrintJob(job_id, document, pages)
        self.queue.append(job)
        print(f"Job '{document}' added to queue.")

    # Dequeue
    def process_job(self):
        if not self.queue:
            print("No jobs in queue.")
            return

        job = self.queue.pop(0)  # FIFO
        print(f"Printing: {job.document} ({job.pages} pages)")

    # Display Queue
    def show_queue(self):
        if not self.queue:
            print("Queue is empty.")
            return

        print("\nPending Jobs:")
        for job in self.queue:
            print(f"ID: {job.job_id}, {job.document}, Pages: {job.pages}")
